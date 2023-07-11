#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 10;
    char c = 'A';

    void *ptr = &i;// con trỏ đặc biệt 

    printf("giá trị của i: %d, địa chỉ của i: %p\n",*(int*)ptr, ptr);// ép kiểu giá trị cho con trỏ integer

    return 0;
}
