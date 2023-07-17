#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    for(int i = 0; i<10; i++){
        printf("i= %d\n", i);
        if(i == 5){
            exit(0);
        }
    }
    return 0;
}
