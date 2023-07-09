#include <stdio.h>
int main(int argc, char const *argv[])
        {
   int a[5] = {1, 2, 3 , 4, 5 };

   printf("giá trị của a: %d\n", a); // a là hằng con trỏ
   printf("địa chỉ của phần tử a[0]: %d\n", &a[0]); // giá trị của hằng trỏ là địa chỉ của a[0]
   return 0;
        }