#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

    jmp_buf buf;
    int check_value = 0;

    #define TRY if((check_value = setjmp(buf)) == 0)

    #define CATCH(num) else if (check_value = num)

    #define THROW(num) longjmp(buf, num)

    double thuong (int a, int b){
        if(b == 0){
            THROW(1);
        }
        return (double)a/b;
    }
int main(int argc, char const *argv[])
{
    double kq;

    TRY { // check_value = setjmp(buf)) == 0{
        kq = thuong (12, 0);
        printf("kq: %f\n", kq);
    }

    CATCH(1){ // else if (check_value = 1){
        printf("ERROR, mau bang 0");
    }
    
    return 0;
}
