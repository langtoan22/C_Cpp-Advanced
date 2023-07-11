#include <stdio.h>

void tong(int a, int b){
    printf("tong cua %d va %d: %d\n", a, b, a+b);
}

int main(int argc, char const *argv[])
{
    void (*ptr) = &tong;

    ((void(*)(int a, int b)) ptr) (9, 7); // ép kiểu
    return 0;
}
