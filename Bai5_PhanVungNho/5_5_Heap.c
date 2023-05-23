#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t array[] = {1,2,3,4};

//uint8_t *ptr


int main(int argc, char const *argv[])
{
   // ptr = array;
    
    printf("gia tri: %d\n", *(array + 1));

   // printf("gia tri: %d\n", (ptr + 1));
    return 0;
}
