#include "../include/sys_init.h"
#include "../include/kmain.h"
#include "../include/kstdio.h"
#include <stdint.h>
#include<string.h>

void kmain(void)
{
      __sys_init();


      kprintf((uint8_t*)"%s",(uint8_t*)"Booting OS CSE: \n");
      kprintf((uint8_t*)"%s",(uint8_t*)"Version: 1.0\n");

      kprintf((uint8_t*)"%s",(uint8_t*)"Wellcome .... \n");

     


      // // Enter a character.
      // char ch;
      // kprintf((uint8_t*)"%s",(uint8_t*)"Enter a character :");
      // kscanf((uint8_t*)"%c",(uint8_t*)&ch);
      // kprintf((uint8_t*)"%c",(uint8_t*)&ch);
      
      // kprintf((uint8_t*)"%s",(uint8_t*)"\n");


      // // Enter a string....
      // char s[100];
      // kprintf((uint8_t*)"%s",(uint8_t*)"Enter a string :");
      // kscanf((uint8_t*)"%s",(uint8_t*)&s);
      // kprintf((uint8_t*)"%s",(uint8_t*)&s);
      
      // kprintf((uint8_t*)"%s",(uint8_t*)"\n");


      // Enter a integer value
      int a;
      kprintf((uint8_t*)"%s",(uint8_t*)"Enter an integer :");
      kscanf((uint8_t*)"%d",(uint8_t*)&a);
      kprintf((uint8_t*)"%d",(uint8_t*)&a);
      
      kprintf((uint8_t*)"%s",(uint8_t*)"\n");



      // Enter a hex number
      int hex;

      kprintf((uint8_t*)"%s",(uint8_t*)"Enter a hex number :");
      kscanf((uint8_t*)"%x",(uint8_t*)&hex);
      kprintf((uint8_t*)"%x",(uint8_t*)&hex);
      
      kprintf((uint8_t*)"%s",(uint8_t*)"\n");



      // Enter a float number
      float f;

      kprintf((uint8_t*)"%s",(uint8_t*)"Enter a float number :");

      kscanf((uint8_t*)"%f",(uint8_t*)&f);
      kprintf((uint8_t*)"%f",(uint8_t*)&f);
      
      kprintf((uint8_t*)"%s",(uint8_t*)"\n");


}

