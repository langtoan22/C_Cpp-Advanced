#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 5

typedef struct{
    int8_t rear;
    int8_t front;
    int8_t array[SIZE];
}Queue;

// queueInit(): hàm tạo queue
    void QueueInit (Queue *queue){
        queue -> rear = 0;
        queue -> front = 0;
    }

// enqueue(): Inserts an element at the end of the queue i.e. at the rear end.
    void enqueue (Queue *queue, uint8_t value){
        queue -> array[++(queue -> rear)] = value;
    }

// dequeue(): This operation removes and returns an element that is at the front end of the queue.
    void dequeue (Queue *queue, uint8_t value){
       queue -> array[(queue -> front) ++];
    }
// front(): This operation returns the element at the front end without removing it.
// trả vê giá trị
    uint8_t front (Queue *queue){
         return queue -> array[queue -> front] ;
    }

// rear(): This operation returns the element at the rear end without removing it.
    uint8_t rear (Queue *queue){
         return queue -> array[queue -> rear] ;

    }
// isEmpty(): This operation indicates whether the queue is empty or not.
    bool isempty(Queue *queue) {
         if( queue -> front == -1 && queue -> rear == -1){
            return true;
         }
        else return false;
         }

// isFull(): This operation indicates whether the queue is full or not.
    bool isfull (Queue *queue){
        if(queue->rear == SIZE - 1){
            return true;
        }
        else return false;
    }

// size(): This operation returns the size of the queue i.e. the total number of elements it contains
    uint8_t size (Queue *queue){
        return (queue -> rear) - (queue -> front) + 1;
    }
  
int main(int argc, char const *argv[])
{
    Queue queue;
    QueueInit(&queue);

//them mot phan tu
    enqueue(&queue, 3);
    enqueue(&queue, 2);
    enqueue(&queue, 5);
    enqueue(&queue, 4);
    enqueue(&queue, 1);

// in ra gia tri trong hang doi
    for (uint8_t i = queue.front; i <= queue.rear; i++){
        printf("%d ", queue.array[i]);
    }
    printf("\n%d\n", queue.front);
    printf("%d\n", queue.rear);
  

    printf("Phần tử đầu tiên trong hàng đợi là: %d\n", front(&queue));
    printf("Phần tử cuối cùng trong hàng đợi là: %d\n", rear(&queue));
    printf("kichthuoc: %d \n", size(&queue));
    return 0;
}
