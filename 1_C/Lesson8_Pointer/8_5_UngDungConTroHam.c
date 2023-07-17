#include <stdio.h>

void tong (int a, int b){
    printf("tong %d va %d = %d \n", a, b, a+b);

}
void hieu (int a, int b){
    printf("hieu %d va %d = %d \n", a, b, a-b);
}

void tich (int a, int b){
   printf("tich %d va %d = %d \n", a, b, a*b);

}

void thuong (int a, int b){
   printf("thuong %d va %d = %f \n", a, b, (float)a/b);
}

void PhepTinh(int a, int b, void (*ptr)(int a, int b)){
    printf("chuong trinh tinh: \n");
    ptr(a,b);
}

int main(int argc, char const *argv[])
{
    PhepTinh(8, 6, &tong);
    PhepTinh(8, 6, &hieu);
    PhepTinh(8, 6, &tich);
    PhepTinh(8, 6, &thuong);

    return 0;
}
