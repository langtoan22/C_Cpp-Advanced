#include <iostream>
using namespace std;

class ToanHoc{
    public: 
        void tong(int a, int b);
        void tong(int a, int b, int c);
        int tong(int a, double b);
};

void ToanHoc::tong (int a, int b){
    printf("tong a va b: %d\n", a+b);
}

void ToanHoc::tong (int a, int b, int c){
    printf("tong a va b va c: %d\n", a+b+c);
}
int ToanHoc::tong(int a, double b){
    return a + (int)b;
}
int main(int argc, char const *argv[])
{
    ToanHoc th;
    th.tong(7,2);
    th.tong(7,2,6);
    printf("tong: %d\n", th.tong(3, 5.5));
    
    
    return 0;
}
