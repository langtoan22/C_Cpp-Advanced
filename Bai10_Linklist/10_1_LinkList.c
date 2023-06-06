#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


// định nghĩa hàm liên kết
struct Node {
   uint8_t value; 
   struct Node *next;
};
 typedef struct Node node;

// hàm tạo liên kết mới và cấp phát động với dữ liệu uint8_t là value
 node *createNode(uint8_t value){
    node *node2 = (node*) malloc(sizeof(node));
    node2->value = value;
    node2->next = NULL;
    return node2;
 }

// hàm thêm 1 node
void push_back(node **array, uint8_t value){ 
   node *temp, *p;
   temp = createNode(value);

//kiểm tra giá trị của array bằng NULL
   if(*array = NULL){ 
      *array = temp;
   }
   else{

   // từ node thứ 2 khi array khác NULL thì giá trị con trỏ(địa chỉ) array được gán cho con trỏ p
      p = *array;
   // p trỏ đến next kiểm tra khách NULL
      while(p->next != NULL){
         p = p->next;
      }
      p->next = temp;
   }
}
 int main(int argc, char const *argv[])
 {

   // node * array;  

   // array = createNode(6);
   node *array = NULL; // 0xc1

   push_back(&array, 6);
   push_back(&array, 2);
   push_back(&array, 7);


    return 0;
 }
 