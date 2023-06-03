#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct Node {
   uint8_t value; 
   struct Node *next;
};
 typedef struct Node node;

// cấp phát động với dữ liệu uint8_t là value
 node *createNode(uint8_t value){
    node *node2 = (node*) malloc(sizeof(node));
    node2->value = value;
    node2->next = NULL;
    return node2;
 }


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
    node *array = NULL; // 0xc1

    push_back(&array, 6);


   

    return 0;
 }
 