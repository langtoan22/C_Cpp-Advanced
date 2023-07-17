#include <stdio.h>

void swap (int a, int b){
    printf("a: %d, dia chi: %p\n", a, &a);
    printf("b: %d, dia chi: %p\n", b, &b);
    int temp = a;
    a = b;
    b = temp;
}

void swap2 (int *a, int *b){
    printf("a: %d, dia chi: %p\n", *a, a);
    printf("b: %d, dia chi: %p\n",*b, b);
    int temp = *a; //luu gia tri cua bien ma con tro a dang tro toi
    *a = *b; // gan gia tri cua bien ma con tro b dang tro toi cho gia tri a dang tro toi
    *b = temp; //gan gia tri duoc luu cho con tro b dang tro toi
}

int main(int argc, char const *argv[])
{
    int so1 = 10, so2 = 20;

    printf("so1 = %d, diachi: %p\n", so1, &so1);
    printf("so2 = %d, diachi: %p\n", so2, &so2);

    swap2(&so1, &so2);
    printf("so1: %d, so2: %d", so1, so2);
    return 0;
}
