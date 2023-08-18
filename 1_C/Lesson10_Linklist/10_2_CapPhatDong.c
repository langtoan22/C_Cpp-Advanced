#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    uint8_t a[] = { 1, 4, 5, 7, 8};
    uint8_t *ptr = (uint8_t *)malloc(sizeof(uint8_t)*3);// mở 3 byte

    ptr[0] = 7;
    ptr[1] = 8;
    ptr[2] = 9;

    for(int i = 0; i < 3; i++){
        printf("test: %d, dia chi: %p\n", ptr[i],ptr+i);
    }

    for (int i = 0; i < 3; i++){
        ptr[i] = 2*i;
    }

    ptr = (uint8_t*) realloc(ptr, sizeof(uint8_t)*8); // mở thêm 5 byte, từ 3 lên 8byte
   
   for (int i = 0; i < 8; i++){
        ptr[i] =  3*i;
    }
    for (int i = 0; i < 8; i++){
        printf("test2: %d, dia chi: %p\n",ptr[i], ptr+i);
    }

    return 0;
}
