#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct Node {
    uint8_t value;
    struct Node *next;
};
typedef struct Node node;

node *createNode (uint8_t value){
    node *newnode = (node*) malloc(sizeof(node));
    newnode -> value = value;
    newnode -> next = NULL;

    return newnode;
}

void push_back (node **array, uint8_t value){
    node *temp, *p;
    temp = createNode(value);
    
    if(*array == NULL){
        *array = temp;
    }
    else{
        p = *array;
        while(p->next != NULL){
            p = p -> next ;
        }
         p -> next = temp;
    }
}

int main(int argc, char const *argv[])
{
    node *array = NULL;

    push_back(&array,6);
    push_back(&array, 4);
    push_back(&array, 7);
    return 0;
}
