#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union 
{

uint32_t var1;
uint16_t var2;
uint64_t var3;

}typeData;

// void hienthi(typeData data){
//    printf("var1: %d, var2: %d, var3: %d", Data.var1, Data.var2, Data.var3);

// }
 int main(int argc, char const *argv[])
 {
    typeData data = {.var1 = 2, .var2 = 7, .var3 = 9};
    
   //typeData Data
   //  Data.var1 = 2;
   //  Data.var2 = 7;
   //  Data.var3 = 9;
   // hienthi(Data);

   printf("test1: %d\ntest2: %d\ntest3: %d\n",data.var1, data.var2,data.var3);

   printf("Dia chi union: %p\n",&data);
   printf("Dia chi union: %p\n",&data.var1);
   printf("Dia chi union: %p\n",&data.var2);
   printf("Dia chi union: %p\n",&data.var3);

   printf("size union: %d\n",sizeof(data));

    return 0;
 }
 

