#include <stdio.h>

/*dinh nghia Max moi #define se tuong ung mot doan code if elif else 
#define  15 
#define  20
#define  24 
*/
//---------------
#define Max 24

#if Max < 20
    void test (){
        printf("Max < 20\n");
    }

#elif Max == 20
    void test (){
        printf("Max == 20\n");
    }

#else 
    void test (){
        printf("Max > 20\n");
    }

#endif

int main(){
    test();
}