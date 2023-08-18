#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


//khai bao cau truc cua 1 node
struct Node {
    uint8_t value;
    struct Node *next;
};
typedef struct Node NODE;

// hàm tạo node mới và cấp phát động với dữ liệu uint8_t là value
 NODE *createNode(uint8_t value){
    NODE *newNode = (NODE*) malloc(sizeof(NODE));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
 }

// hàm duyệt 
void duyet(NODE* head){
   while(head != NULL){
      printf("%d, ", head -> value);
      head = head -> next;
   }
}

//hàm thêm một node ở đầu DSLK

void pushFront(NODE* *head, uint8_t value){
   NODE *newNode = createNode(value);

   if(*head == NULL){ // khi gia tri cua con tro ** head tức *head của con trỏ **head == null là không  trỏ đến địa chỉ của node nào trong danh sách
      *head = newNode; // cập nhật con trỏ head trỏ vào địa chỉ của node mới
   }
   else{
       newNode -> next = *head;  //  con trỏ next của node mới sẽ trỏ đến node đằng sau                      
      *head = newNode; // cập nhật con trỏ head trỏ vào địa chỉ của node mới 
   
   }
  
}

// hàm thêm 1 node ở cuối danh sách
void push_back(NODE* *head, uint8_t value){ 
   NODE *newNode = createNode(value);
   NODE *temp  = *head;

   if(*head == NULL){ 
      *head = newNode; // *head là địa chỉ của node đầu tiên trong dslk
      return;
   }
   else{
      while (temp ->next != NULL){
            temp = temp ->next;
      }
      //cho next cua temp tro den newNode
      temp -> next = newNode;
    
   }
}

 int main(int argc, char const *argv[])
 {

   NODE *head = NULL; // 0xc1

   for (int i = 1; i <= 10; i++){
      //push_back(&head, i);
      pushFront(&head, i);
   }

   duyet(head);
   
     
      
   return 0;
 }