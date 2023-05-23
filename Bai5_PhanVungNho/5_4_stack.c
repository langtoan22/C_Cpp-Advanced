#include <stdio.h>
#include <stdint.h>


void swap (int a, int b){
    int temp = a;
        a = b;
        b = temp;
}

int main(int argc, char const *argv[])
{

    int soDau = 15;
    int soCuoi = 20;

    swap(soDau, soCuoi);

    printf("soDau: %d\nsoCuoi: %d\n", soDau, soCuoi);
    return 0;
}

