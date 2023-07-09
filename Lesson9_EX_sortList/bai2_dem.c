#include <stdio.h>
#include <stdint.h>
#include <string.h>

//cho mang ngau nhien: uint8_t array[] = {1, 3, 5, 2, 3, 4, 5, 6, 2, 6, 9, 6, 7}
//dem so lan xuat hien

void demSolanXuatHien (uint8_t array[], uint8_t soLuong){
    uint8_t dem[256];

    //khoi tao gia tri mang count bang 0
    memset(dem, 0, sizeof(dem));

    //duyet qua mang array dem cac phan tu i co bao nhieu lan xuat hien
    for(int i = 0; i < soLuong; i++){
        dem[array[i]]++;
    }
    //in ra cac gia tri co so lan xuat hien > 0
    for(int i = 0; i < 256; i++){
        if(dem[i] > 0){
            printf("so lan xuat hien cua %d la: %d\n", i, dem[i]);
        }
    }

}

int main(int argc, char const *argv[])
{
    uint8_t array[100], soLuong;
    printf("nhap so luong cua mang: \n");
    scanf("%d", &soLuong);

    printf("nhap cac phan tu trong mang: \n");
    for(int i = 0; i < soLuong; i++){
    scanf("%d",&array[i]);
    }

    demSolanXuatHien(array, soLuong);
    return 0;
}

