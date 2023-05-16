#include <stdio.h>

//de noi chuoï trong macro dung ##
//de xuong dong dung "\"
#define variable(name) int int_##name; \ 
char char_##name ;                     \
double double_##name

int main(){

    variable(bien);
    int_bien = 20;
    char_bien = 'A';
    double_bien = 10.2;

    printf("int: %d\n", int_bien);
    printf("char: %c\n", char_bien);
    printf("double: %.2f\n", double_bien);

    return 0;
}