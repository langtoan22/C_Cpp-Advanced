#include <iostream>
using namespace std;


template <typename var1, typename var2>

 var1 tong (var1 a, var2 b){
    return (var1) (a+b);
 }
int main(int argc, char const *argv[])
{
    printf("tong: %f", tong(12, 12.5));

    return 0;
}

