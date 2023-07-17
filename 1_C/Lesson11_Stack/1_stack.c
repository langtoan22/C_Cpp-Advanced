#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 5

uint8_t i = -1;

// return true if stack empty else false
    bool isEmpty(){
    if(i == -1){
        return true;
    }
    else{
        return false;
    }
 }

 // return true if stack is full else false
    bool isFull(){
        if(i == SIZE - 1){
            return true;
        }
        else{
            return false;
        }
    }

// to insert an elememt into the stack
    void push(uint8_t stack[], uint8_t value){
        if(isFull() == true){
            printf("stack is full\n");
        }
        else{
            ++i;
            stack[i] = value;
        }
    }

// to remove an element from the stack
    void pop(uint8_t stack[]){
        if(isEmpty() == true){
            printf("stack is empty\n");
        }
        else {
            stack[i--] =='\0';
        }
    }

// return the top element of the stack
    uint8_t top (const uint8_t stack[]){
        return stack[i];
    }

// return the size of the stack
    uint8_t size(){
        return i + 1;
    }
int main(int argc, char const *argv[])
{
    uint8_t stack[SIZE];

    push(stack, 1);
    push(stack, 2);
    push(stack, 32);
    push(stack, 4);
    push(stack, 5);
    
    pop(stack);
    pop(stack);
    
    printf("top: %d\n", top(stack));
    printf("size: %d\n", size());
    return 0;
}
