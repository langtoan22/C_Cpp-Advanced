#include <stdio.h>
#include <stdint.h>

typedef struct{

    uint8_t ngay;// 1 byte = 1 byte + 2 byte + 1 byte đệm = 4 byte
    uint16_t thang;// 2 byte =  dung vao bo dem cua "ngay"
    uint32_t nam;// 4 byte =  4 byte
    // sizeof = 8 byte

}typeDate;

int main(int argc, char const *argv[])
{
    typeDate Date;
        printf("size: %d",sizeof(Date));

    return 0;
}
