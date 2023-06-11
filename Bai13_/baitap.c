#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 50
#define MIN_VALUE 1
#define MAX_VALUE 10

void createArray(uint8_t arr[]){

    uint8_t i;

    // khoi tao cho rand()
    srand(time(NULL));

    // Tao mang ngau nhien trong pham vi MIN_VALUE, MAX_VALUE
    for (i = 0; i < SIZE; i++) {
        arr[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    }
}


void swap (uint8_t arr[], int i, int j){
    uint8_t temp =  arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// ham sap xep
void sortList (uint8_t arr[]){
    for(int i = 0; i< SIZE - 1; i++){
        for(int j = 0; j < SIZE - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}

//ham tim kiem nhi phan
bool binarySearch (uint8_t arr[], uint8_t x){
    uint8_t left = 0; uint8_t right = SIZE - 1;

    while(left <= right){
        uint8_t mid = (left + right)/2;
        if(arr[mid] == x){
            return true; // tim thay
        }
        //tim ben phai (left = mid + 1)
        else if(arr[mid] < x){
            left = mid + 1;
        }
        //tim ben trai (right = mid - 1)
        else{
            right = mid -1;
        }
    }
    return false;
}
int main() {
    uint8_t x;
    uint8_t arr[50];

    createArray(arr);

    sortList(arr);


     // In ra mang

    printf("Mang ngau nhien: \n");
    for (uint8_t i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //tim kiem
    while(1){
        printf("nhap gia tri x can tim: ");
        scanf("%d", &x);

        if(x < 0 || x > 10){
            printf("khong co gia tri can tim");
            break;
        }
        else if (binarySearch(arr, x)){
        printf ("tim thay\n");
        }
        else printf("khong tim thay");
    }
    return 0;
}