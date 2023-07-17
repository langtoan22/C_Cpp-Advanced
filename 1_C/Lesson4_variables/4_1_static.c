#include <stdio.h>
#include <stdint.h>

    void count (){
        uint8_t temp = 0;
        printf("temp: %d\n", temp);
        temp++;
    }

    void count2(){
        static uint8_t temp = 0;
        printf("temp: %d\n", temp);
        temp++;
    }

int main(){

    count();
    count();
    count();

    count2();
    count2();
    count2();
}