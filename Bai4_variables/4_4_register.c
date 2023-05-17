#include <stdio.h>
#include <stdint.h>
#include <time.h>



int main()
{
   clock_t start, end; //clock_t: typedef unsign long

   register uint32_t i;

   start = clock();  //1s

   for (i = 0; i < 0xFFFFFFFF; i++); //3s

   end = clock();    //4s

   printf("time: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
   

    return 0;
}