#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}; typedef struct Node NODE;


// thêm node đồng thời sắp xếp node từ bé đến lớn
void addNode (NODE* *head, int value){
    NODE *newNode = (NODE *) malloc (sizeof(NODE));
    newNode ->data = value;
    newNode -> next = NULL;

    if(*head == NULL || (*head) -> data > value ){
        newNode ->next = *head;
        *head = newNode;
        return;
    }
    NODE *temp = *head;

//điều kiện để duyệt đi từng node
    while (temp ->next != NULL && temp ->next ->data < value){
        temp = temp ->next;
    }

    newNode->next = temp->next;
    temp ->next = newNode;

}

int main(int argc, char const *argv[])
{
    NODE *head = NULL;
    return 0;
}
