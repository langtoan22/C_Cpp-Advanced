#include <stdio.h>
#include <stdint.h>

const uint8_t temp = 15; //bien toan cuc

static uint8_t test = 21;  //bien static toan cuc khoi tao vơi gia tri khac 0

void hienthi(){
    static uint8_t i = 23; //bien cuc bo static
}

int main(int argc, char const *argv[])
{
    int temp = 23; //co the thay doi gia tri
    
    printf("test: %d\n", temp);
    return 0;
}
