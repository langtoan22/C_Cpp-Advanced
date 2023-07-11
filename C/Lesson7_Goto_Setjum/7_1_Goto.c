#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    int phim = 0;
    char ten[20];
    uint8_t tuoi;

    vitri_ten:

    printf("nhap ten: ...");
    scanf("%s", &ten);

    if(0){
        goto vitri_ten;
    }

    vitri_tuoi:

    printf("nhap tuoi: ... ");
    scanf("%d", &tuoi);
    
    if(0){
        goto vitri_tuoi;
    }

    return 0;
}

