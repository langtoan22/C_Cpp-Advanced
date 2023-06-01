#include <stdio.h>
#include <stdint.h>

//cho mang ngau nhien: uint8_t array[] = {1, 3, 5, 2, 3, 4, 5, 6, 2, 6, 9, 6, 7}
// hay sap xep theo thu tu tu be den lon


void sortList ( uint8_t soLuong, uint8_t array[]){
    for(int i = 0; i < soLuong - 1; i++){

    // dung 1 bien de luu gia tri nho nhat
       int  min_index = i;

       // Duyet tat ca cac phan tu dung sau phan tu hien tai va cap nhat lai gia tri nho nhat
        for(int j = i+1; j < soLuong; j++){
            if(array[j] < array [min_index]){
                min_index = j;
            }
        }

        // doi vi tri cua gia tri thu i voi gia tri nho nhat
          uint8_t temp = array[i];
          array[i] = array[min_index];
          array[min_index] = temp;
    }
}

int main(int argc, char const *argv[])
{
    uint8_t soLuong;
    uint8_t array [100];
    printf("nhap so luong cua mang: ");
    scanf("%d", &soLuong);

    printf("nhap cac phan tu cua mang: \n");
    for(int i = 0; i < soLuong; i++){
        scanf("%d", &array[i]);
    }
    //goi ham sap xep
    sortList(soLuong, array);

    // in ra mang sau khi sap xep
    printf("mang sau khi sap xep: \n");
    
    for(int i = 0; i < soLuong; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
