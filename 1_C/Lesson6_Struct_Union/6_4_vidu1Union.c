#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union 
{

uint8_t var1; // char
uint16_t var2; // long
uint64_t var3;  //

}typeData;

int main(int argc, char const *argv[])
{
    typeData data = {.var2 = 1234};

    printf("test1: %d\ntest2: %d\ntest3: %d\n",data.var1, data.var2,data.var3);

    return 0;
}
