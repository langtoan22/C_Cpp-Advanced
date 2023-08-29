#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} NODE;

// them node vao danh sach dong thoi sap xep tu be den lon

void addNode(NODE ** head, int value){
    NODE *newNode = (NODE*) malloc (sizeof(NODE));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL || (*head)->data >= value){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    NODE *temp = *head;

    while (temp->next != NULL && temp->next->data < value){
        temp = temp->next;
    }
    
    newNode->next = temp->next;
     temp ->next = newNode;
    
}

// tao kieu du lieu centerpoint

typedef struct centerpoint {
    int value;
    centerpoint *left;
    centerpoint *right;
} CenterPoint;

// tim diem giua cua phia ben trai va phia ben phai

CenterPoint *buildTree(NODE *head, int start, int end){

    if(head == NULL || start > end){
        return NULL;
    }

    NODE *temp = head;
    int mid = (start + end)/ 2;
    for(int i = start ; i < mid; i++){
        if (temp->next == NULL){
            break;
        }
    temp = temp ->next;
    }
    CenterPoint *root = (CenterPoint*) malloc (sizeof(CenterPoint));

    root ->value = temp->data;
    root->right = buildTree(temp->next, mid + 1, end);
    root->left = buildTree(head, start, mid -1);

return root;
}

// tim diem giua va tao cay

CenterPoint *diemGiua(NODE *head){
    int length = 0;
    NODE *temp = head;

   while(temp != NULL){
    temp = temp->next;
    length ++;
   }

   return buildTree(head, 0 , length -1);
}

// tim kiem

CenterPoint *binarySearch( CenterPoint *root, int value){
    static int loop = 0;
    loop ++;
    printf("so lan lap: %d,\n", loop);

    if(root == NULL){
        return NULL;
    }

    if(root ->value == value){
         return root;
    }
    if(root->value < value){
        return binarySearch(root->right, value);
    }

    else {
        return  binarySearch(root->left, value);
    }
}


// in gia tri cac node ra man hinh
void displayList (NODE *head){
    while(head != NULL){
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
    
}
int main(int argc, char const *argv[])
{
    NODE *head = NULL;

    // tao 10000 node bat ki 
    srand(time(NULL));

    for(int i = 0; i < 10000; i++){
        int value = rand () % 10000 + 1;
        addNode(&head, value);
    }
    
    addNode(&head, 6087);


    // in 10000 node ra man hinh
    displayList(head);

    int value = 6087;
    CenterPoint *ptr = diemGiua(head);
    CenterPoint *result = binarySearch(ptr, value);

    if(result != NULL){
        printf(" tim thay: %d", value);
    }
    else{
        printf("khong tim thay: %d", value);
    }

    return 0;
}
