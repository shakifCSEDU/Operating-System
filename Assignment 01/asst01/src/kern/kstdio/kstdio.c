#include "../include/kstdio.h"
#include"../arch/stm32f446re/include/dev/usart.h"
/**
* first argument define the type of string to kprintf and kscanf, 
* %c for charater
* %s for string, 
* %d for integer
* %x hexadecimal
* %f for floating point number
*/


// here we find the integer value..
void my_memcpy(char *temp,uint8_t *a,uint8_t n)
{
    for(int i =0  ; i<n ; i++){
        temp[i] = a[i];
    }
}

int power(int num,int pow){

	int ans = 1;

	while(pow != 0){

		ans *= num;
		pow--;
	}

	return ans;
}

void convert_int_to_string(int a,char *ch)
{
	
    int i = 0;

    while(a != 0){
        ch[i++] = (char)( (a % 10) + 48 );
        a/=10;
    }
    ch[i] = '\0';
	int len = i;

    for(i = 0 ;i<len/2 ; i++)
    {
        char tmp = ch[i];
        ch[i] = ch[len-i-1];
        ch[len-i-1] = tmp;
    }
}
void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
 
    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
 
    reverse(str, i);
    str[i] = '\0';
    return i;
}

void convert_float_to_string(float n,char *ch,int afterpoint){
	int ipart = (int)n;
 
    // Extract floating part
    float fpart = n - (float)ipart;
 
    // convert integer part to string
    int i = intToStr(ipart, ch, 0);
 
    // check for display option after point
    if (afterpoint != 0) {
        ch[i] = '.'; // add dot
 
        fpart = fpart *(float)power(10, afterpoint);
 
        intToStr((int)fpart, ch + i + 1, afterpoint);
}
}

void convert_int_to_hex(int temp,char *ch){
	
	int decimalNumber,quotient;
	decimalNumber = temp;

	quotient = decimalNumber;
	int i = 0;
	while(quotient != 0) {
		temp = quotient % 16;
		//To convert integer into character
		if( temp < 10)
		    temp =temp + 48; 
		else
		    temp = temp + 55;
		ch[i++] = temp;
		quotient = quotient / 16;
	}
	ch[i] = '\0';
	int len = i;

    for(i = 0 ;i<len/2 ; i++)
    {
        char tmp = ch[i];
        ch[i] = ch[len-i-1];
        ch[len-i-1] = tmp;
    }
}

void convertStringToInt(uint8_t* arr, uint32_t* num){

	int size = 0;

	int i = 0;

	while(arr[i] != '\0'){

		i++;
		size++;
	}

	i = 0;

    *num = 0;

	size--;

	while(size >= 0){

		(*num) += (int)(arr[size]-'0')*power(10,i);
		i++;
		size--;
	}
}


void convertHexStringToInt(uint8_t* arr, uint32_t* num) {

	int size = 2;

	int i = 2;
	while(arr[i] != '\0'){

		i++;
		size++;
	}


	i = 0;
	uint32_t ans = 0;

	size--;

	while(size >= 0){

		if (arr[size] == 'A' || arr[size] == 'B' || arr[size] == 'C' || arr[size] == 'D' || arr[size] == 'E' || arr[size] == 'F'){

			ans += (int)(arr[size]-'A'+10)*power(16,i);

		}else if (arr[size] == 'a' || arr[size] == 'b' || arr[size] == 'c' || arr[size] == 'd' || arr[size] == 'e' || arr[size] == 'f'){
			
			ans += (int)(arr[size]-'a'+10)*power(16,i);

		}else{

			ans += (int)(arr[size]-'0')*power(16,i);
		}

		i++;
		size--;
	}

    *num = ans;
}

float convert_string_to_float(uint8_t* inp){

	int i = 0,j;
    float f;
    float mantissa = 0.0f;

    while(inp[i] != '\0' && inp[i] !='.')i++;
    int len1 = i;

    for(i = 0 ; i<len1 ; i++){
       mantissa = mantissa*10 +  (inp[i]-'0');
    }

    float exponent = 0.0f;

    i = len1+1;

    while(inp[i] != '\0')i++;
    int len2 = i;

    for(i = len1+1,j = -1 ; i<len2 ; i++,j--){
        exponent = exponent + power(10,j)*(inp[i]-'0');
    }
    f = (mantissa+exponent);
	return f;
}


void convertStringToFloat(uint8_t* arr, float* num)
{
    int size = 0;
    int i = 0;
    int isNegative = 0;

    if(arr[i] == '-'){
        isNegative = 1;
        size++;
        i++;
    }

    while(arr[i] != '.'){
        i++;
        size++;
    }

    i = 0;
    (*num) = 0.0;
    int fractionalPartStartIndex = size+1;
    size--;

    while(arr[size] != '-' && size >= 0){
        (*num) += (float)((arr[size]-'0')*power(10,i));
        i++;
        size--;
    }

    i = 1;
    float multiplier = 1.0;

    while(arr[fractionalPartStartIndex] != '\0'){

        multiplier = multiplier*1/10;
        (*num) += (arr[fractionalPartStartIndex]-'0')*multiplier;
        i++;
        fractionalPartStartIndex++;
    }

    if (isNegative == 1){
        (*num) = -(*num);
    }    
}


void kprintf(uint8_t *format,uint8_t* outvar)
{
	format++;

	if(*format == 's' || *format == 'c')
		_USART_WRITE(USART2,outvar);
		
	else if(*format == 'd')
	{
		int temp;

		my_memcpy((char*)&temp, outvar, sizeof(int));
		
		char ch[100];

		convert_int_to_string(temp,ch);
		_USART_WRITE(USART2,(uint8_t*)ch);

	}

	
	else if(*format == 'x'){
		int temp;
		my_memcpy((char*)&temp, outvar, sizeof(int));
		char ch[100];
		
		convert_int_to_hex(temp,ch);
		_USART_WRITE(USART2,(uint8_t*)ch);
	}


	else if(*format == 'f'){
		float temp;
		my_memcpy((char*)&temp, outvar, sizeof(float));
		char ch[100];
		convert_float_to_string(temp,ch,6);
		_USART_WRITE(USART2,(uint8_t*)ch);
	}


}



void kscanf(uint8_t *format,uint8_t* invar)
{
	format++;
	
	if(*format == 'c') {
        _USART_READ(USART2, invar, 2);

    }

	else if(*format == 's'){
        _USART_READ(USART2, invar, 1000);
	}

	else if(*format == 'd'){

		uint8_t inp[13];
        _USART_READ(USART2, inp, 1000);
		uint32_t* x = (uint32_t*) invar;
        
		convertStringToInt((uint8_t*) inp, x);
	  

	}

	else if(*format == 'f'){
		uint8_t inp[13];

        _USART_READ(USART2, inp, 1000);

        float* x = (float*) invar;
        convertStringToFloat((uint8_t*) inp, x);

	}

	else if(*format == 'x'){
		
		uint8_t inp[13];
		_USART_READ(USART2, inp, 1000);

        uint32_t* x = (uint32_t*) invar;

        convertHexStringToInt((uint8_t*) inp, x);
	
	}

	else{
		_USART_WRITE(USART2,(uint8_t*)"Invalid Input..");
	}

}




