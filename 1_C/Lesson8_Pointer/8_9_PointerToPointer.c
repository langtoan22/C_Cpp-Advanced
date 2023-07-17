#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *ptr = &a;
    int **ptr1 = &ptr;


    printf("gia tri cua bien a: %d\n", a);
    printf("dia chi cua bien a: %d\n", &a);

    printf("gia tri cua bien trong ptr: %d\n", *ptr);
    printf("dia chi cua bien trong ptr: %d\n", ptr);

    printf("gia tri cua bien trong ptr1: %d\n", **ptr1);
    printf("dia chi cua bien trong ptr1: %d\n", ptr1);

    return 0;
}
