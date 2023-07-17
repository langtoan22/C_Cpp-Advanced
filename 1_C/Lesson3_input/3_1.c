#include <stdio.h>
#include <stdarg.h>

int tong (int a, int b, int c){
    return a+b+c;
}

int main (){
    printf("tong la: %d", tong(8, 9 , 10));
    
    return 0;
}