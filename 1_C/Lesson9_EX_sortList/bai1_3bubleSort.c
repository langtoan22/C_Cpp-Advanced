#include <stdio.h>
#include <stdint.h>

//cho mang ngau nhien: uint8_t array[] = {1, 3, 5, 2, 3, 4, 5, 6, 2, 6, 9, 6, 7}
// hay sap xep theo thu tu tu be den lon

// ham thay doi gia vi tri 
void swap (uint8_t array[], int i, int j){
    int temp =  array[i];
    array[i] = array[j];
    array[j] = temp;
}

void sortList (uint8_t soLuong, uint8_t array[]){
    for(int i = 0; i< soLuong - 1; i++){
        for(int j = 0; j < soLuong - i - 1; j++){
            if(array[j] > array[j+1]){
                swap(array, j, j+1);
            }
        }
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
