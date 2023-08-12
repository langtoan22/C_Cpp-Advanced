#include <stdio.h>
#include <stdarg.h>

//tinh tong voi cac so khong co dinh

int tong(int so_input,...){                         //co the thay the kieu dư lieu
    int sum = 0;
    va_list va;                                     //luu tru cac bien doi so voi ten "va"
    va_start (va, so_input);                        //truy cap vao danh sach luu tru cac bien doi so, va cap nhat con tro

    for(int i = 0; i < so_input; i++){

        int num = va_arg(va, int);
        printf("test: %d\n", num);   //co the thay the kieu dư lieu
                  
        sum = sum + num;               // va_arg(va, int): lay cac bien doi trong danh sach theo kieu dư lieu, va cap nhap vi tri con tro
        
    }

    va_end(va);
    
    return sum;
}
int main(){
    //tong(5, 1, 4, 7, 8, 9);
    printf("tong cac so la: %d\n",tong(5, 1, 2, 3, 4, 5));
    return 0;
}