//单循环链表
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* initList(){
    Node* L = (Node*)malloc(sizeof(Node));
    L->data = 0;
    L->next = L;
    return L;
}

void headInsert(Node* L, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    L->next = node;
    L->data ++;
}

void tailInsert(Node* L, int data){
    Node* n = L;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    while(n->next != L){
        n = n->next;
    }
    node->next = L;
    n->next = node;
    L->data ++;
}

int delete(Node* L, int data){
    Node* node = L->next;
    Node* preNode = L;
    while(node->next != L){
        if(node->data == data){
            preNode->next = node->next;
            free(node);
            L->data --;
            return TRUE;
        }
        preNode = node;
        node = node->next;
    }
    return FALSE;
}

void printList(Node* L){
    Node* node = L->next;
    while(node != L){
        printf("%d->",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    Node* L = initList();
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    headInsert(L, 5);
    tailInsert(L, 6);
    tailInsert(L, 7);
    printList(L);
    delete(L, 4);
    printList(L);
    delete(L, 7);
    printList(L);
    delete(L, 5);
    printList(L);

    return 0;
}