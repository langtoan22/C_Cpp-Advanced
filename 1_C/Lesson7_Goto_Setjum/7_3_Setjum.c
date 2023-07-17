#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

int main(int argc, char const *argv[])
{
    jmp_buf jumb;
    int i = setjmp(jumb); // = 0

    printf("i: %d\n",i); // in ra gia tri 0

    if (i!= 0) // khong co gia tri nao khac 0 nên khong chay qua ham if
    {
        exit(0); 
    }

    longjmp(jumb, 1);// khoi tao = 1

    printf("test\n"); // in ra = 1, sau do se quay lai setjmp va tra lai gia tri i= 1 khi do den exit se dung


    return 0;
}
