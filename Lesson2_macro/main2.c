#include <stdio.h>

#define Max 10

#define tong(a,b) a+b

//ktra define tren duoc dinh nghia hay chua, 
//neu roi thi trong ifndef se khong duoc chon, trong main2.i se khong co int a = 10

#ifndef Max
int a = 10;
#endif

//nguoc lai cua ifndef
//chua duoc dinh nghia nen se xuat hien trong main2.i
#ifdef Max
int a = 25;
#endif

int main(){
    //code
    return 0;
}