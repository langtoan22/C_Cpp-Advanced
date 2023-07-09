#include <stdio.h>
#include <stdint.h>
#include <time.h>

volatile uint8_t a;

volatile inţ test = 10;

int readDatafromUART ();


int main()
{
    while(1){
        test = int readDatafromUART ();
        A();
        B();
        C();
    }

    return 0;
}