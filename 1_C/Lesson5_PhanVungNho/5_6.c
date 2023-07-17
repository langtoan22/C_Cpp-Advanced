#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

   // uint16_t *ptr =(uint16_t*) malloc(sizeof(uint16_t)*5); //khoi tao 1 mang su dung malloc tong quat
    uint8_t *ptr = malloc (5);

    for(int i = 0; i<5; i++){
        ptr[i] = 2*i;
    }

    for(int i = 0; i<5; i++){
        printf("i= %d\n", ptr[i]);
    }
    return 0;
}
