#include <stdio.h>
#include <stdint.h>

extern void count();
extern uint8_t temp;

int main(){

    count();
    count();

    temp = 35;

    printf("temp: %d\n", temp);
    
    count();

return 0 ;
}