#include <stdio.h>

typedef struct{
    
    int ngay;
    int thang;
    int nam;
    
}typeDate;

void hienthi(typeDate Date){
    printf("ngay: %d, thang: %d, nam: %d\n",Date.ngay, Date.thang, Date.nam);

}

int main(int argc, char const *argv[])
{

    
    //có the khai bao cach khac
    //typeDate Date = {.ngay = 23, .thang = 5, .nam = 2023};

    typeDate Date;

    Date.ngay = 23;
    Date.thang = 5;
    Date.nam = 2023;
    hienthi(Date);

printf("Dia chi struct: %p\n",&Date);
   printf("Dia chi struct: %p\n",&Date.ngay);
   printf("Dia chi struct: %p\n",&Date.thang);
   printf("Dia chi struct: %p\n",&Date.nam);
    return 0;
}
