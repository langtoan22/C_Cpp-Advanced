#include<iostream>
#include <stdlib.h>
using namespace std;

// nhap danh lien ket don la cac so nguyen. tim gia tri lon nhat


//khai bao cau truc cua 1 node
struct node{
    int data;
    struct node *next;

}; typedef struct node NODE;

//khai bao cau truc cua lien ket
struct list{
    NODE *pHead; //node quanly dau danh sach
    NODE *pTail;// node quanly cuoi danh sach
}; typedef struct list LIST;

//khoi tao
void khoitao (LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
 
// tao mot node
NODE* CreateNode(int x){
    NODE *newNode = (NODE*) malloc(sizeof(NODE));
    newNode ->data = x;
    newNode ->next = NULL;
    return newNode; //tra ve newnode vua khoi tao
}

//pushfront
void pushFront(LIST &l, NODE *newNode){
    
    //neu danh sach lien ket dang rong
    if(l.pHead == NULL){
        l.pHead = l.pTail = newNode; // node dau = node cuoi = newnode
    }

    else{
        newNode ->next = l.pHead; // con tro newnode lien ket den node phead
        l.pHead = newNode; // cap nhat newnode la node dau phead
    }
}
// pushBack
void pushBach(LIST &l, NODE *newNode){
    //neu danh sach lien ket dang rong
    if( l.pHead == NULL){
        l.pHead = l.pTail = newNode; // node dau = node cuoi = newnode
    }
    else{
        l.pTail -> next = newNode; // contro cau ptail lien ket voi newnode
        l.pTail = newNode; //capnhat ptail = newnode
    }

}

void display(LIST l){
    for (NODE *i = l.pHead; i != NULL; i = i->next){
        cout << i->data << " ";
    }
}

int main(int argc, char const *argv[])
{   
    LIST l;
    khoitao(l);// khoi tao danh sach lien ket
    cout << "nhap so luong phan tu danh sach lien ket: ";
    int soLuong, x;
    cin >> soLuong;

    cout << "nhap gia tri so nguye: ";
    for (int i = 0; i < soLuong; i++){
        cin >> x;
        NODE *newNode = CreateNode(x);
        //pushFront(l, newNode );
        pushBach(l, newNode );
    }
    
    cout << "danh sach lien ket: ";
    display(l);

    return 0;
}
