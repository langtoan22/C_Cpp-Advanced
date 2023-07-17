#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union 
{

uint8_t var1[5]; // char
uint16_t var2[2]; // long

}typeData;

int main(int argc, char const *argv[])
{
    typeData data ;

    for(int i = 0; i < 5; i++){
        data.var1[i] = i; // 0 1 2 3 4
    }

    for(int i = 0; i < 2; i++){
        data.var2[i] = 2*i ;  // 0 2
    }

    for(int i = 0; i < 5 ; i++){
        printf("test1: %d\n", data.var1[i]);
    }
   
    return 0;
}
