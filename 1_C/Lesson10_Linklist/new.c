#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}; typedef struct node NODE;

NODE* createNode( int x){
    NODE* newNode = (NODE*) malloc (sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void duyet(NODE *head){
    while(head != NULL){
        printf("%d, ", head->data);
        head = head->next;
    }
}

// ham them node vao dau danh sach

void push_front(NODE **head, int x){
    NODE* newNode = createNode(x);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->next = *head;
        *head = newNode;
    }
}

// ham them node vao cuoi danh sach
void push_back(NODE **head, int x){
    NODE *newNode = createNode(x);
    NODE *temp = *head;

    if(*head == NULL){
        *head = newNode;
    }
    else{
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int main(int argc, char const *argv[])
{
    NODE *head = NULL;
   

    for(int i = 1; i <= 10; i++){
        //push_front(&head, i);
        push_back(&head, i);
        }

    duyet(head);
    return 0;
}
