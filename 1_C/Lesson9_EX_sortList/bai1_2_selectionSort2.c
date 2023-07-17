#include <stdio.h>
#include <stdint.h>

//cho mang ngau nhien: uint8_t array[] = {1, 3, 5, 2, 3, 4, 5, 6, 2, 6, 9, 6, 7}
// hay sap xep theo thu tu tu be den lon

void sortList (uint8_t soLuong, uint8_t array[]){
    for(int i = 0; i < soLuong -1  ; i++){
        for(int j = i + 1 ; j < soLuong ; j++){ 
            if(array[j] < array[i]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
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
    sortList(soLuong, array);

    printf("mang sau khi sap xep: \n");
    
    for(int i = 0; i < soLuong; i++){
        printf("%d ", array[i]);
    }
    return 0;
}