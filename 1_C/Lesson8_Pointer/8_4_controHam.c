#include <stdio.h>

void tong (int a, int b){
    printf("tong %d va %d = %d \n", a, b, a+b);

}

float tich (float a, float b){
   return a*b;

}

int main(int argc, char const *argv[])
{
    void(*ptr)(int, int);
    ptr = &tong;
    ptr(9,8);

    float(*ptr_tich)(float, float);
    ptr_tich = &tich;
    printf("tich: %f",ptr_tich(5.3, 5.6));
    return 0;
}
