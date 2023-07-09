#include <stdio.h>

#define hien_thi(ten_ham, ten_hoc_sinh, tuoi, lop )\
    void ten_ham(){                                 \
        printf("ten: %s \n", #ten_hoc_sinh);            \
        printf("tuoi: %d \n", tuoi);                   \
        printf("lop: %d \n", lop);                     \
    }

    hien_thi(hocsinhA, nguyen van A, 14, 8);
    hien_thi(hocsinhB, nguyen van B, 15, 9);

int main(){
    hocsinhA();
    hocsinhB();

return 0;
}