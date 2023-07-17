#include <stdio.h>

void tang1 (int a){
    a += 100;
    
}

void tang2(int *a){
    *a += 100;
    
}
int main(int argc, char const *argv[])
{
    int a = 300;

    tang1(a);
    printf("giá trị của a sau khi tang1 ket thuc: %d \n", a);

    tang2(&a);
    printf("gia tri của a sau khi tang2 kết thúc: %d \n", a);
    return 0;
}
