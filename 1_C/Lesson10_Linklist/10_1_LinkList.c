#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


// định nghĩa hàm liên kết
cho tôi biết dấu * ở next, creaternode và 

// hàm tạo node mới và cấp phát động với dữ liệu uint8_t là value
 node *createNode(uint8_t value){
    node *node2 = (node*) malloc(sizeof(node));
    node2->value = value;
    node2->next = NULL;
    return node2;
 }

// hàm duyệt 
void duyet(node *array){
   while(array != NULL){
      printf("%d ", array -> value);
      array = array -> next;
   }
}

//hàm thêm một node ở đầu DSLK

void pushFront(node **array, uint8_t value){
   node *newNode = createNode(value);

   if(*array == NULL){
      *array = newNode;
   }
   else{
       newNode -> next = *array;
      *array = newNode;
   
   }
  
}
// hàm thêm 1 node ở cuối danh sách
void push_back(node **array, uint8_t value){ 
   node *temp, *p;
   temp = createNode(value);
   if(*array = NULL){ 
      *array = temp;
   }
   else{
      p = *array;
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

   // push_back(&array, 6);
   // push_back(&array, 2);
   // push_back(&array, 7);

   pushFront(&array, 6);
   pushFront(&array, 5);
   pushFront(&array, 3);

   duyet(array);
   
     
      
   return 0;
 }