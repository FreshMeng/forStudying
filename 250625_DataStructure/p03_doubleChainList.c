//双链表
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 

typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;

Node* initList(){
    Node* L = (Node*)malloc(sizeof(Node));
    L->data = 0;
    L->pre = NULL;
    L->next = NULL;
    return L;
}

void headInsert(Node* L, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if(L->data == 0){  //链表为空
        node->next = L->next;
        node->pre = L;
        L->next = node;
        L->data ++;
    }
    else{
        node->pre = L;
        node->next = L->next;
        L->next->pre = node;
        L->next = node;
        L->data ++;
    }
}

void tailInsert(Node* L, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    Node* n = L;
    while(n->next){
        n = n->next;
    }
    node->data = data;
    node->pre = n;
    node->next = n->next;
    n->next = node;
    L->data ++;
}

int delete(Node* L, int data){
    Node* node = L->next;
    while(node){
        if(node->data == data){
            if(node->next){
                node->pre->next = node->next;
                node->next->pre = node->pre;
            }
            else{
                node->pre->next = node->next;
            }
            free(node);
            L->data --;
            return TRUE;
        }
        node = node->next;
    }
    return FALSE;
}

void printList(Node* L){
    Node* node = L->next;
    while(node){
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    Node* L = initList();
    tailInsert(L, 5);
    tailInsert(L, 6);
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    printList(L);
    delete(L, 1);
    printList(L);
    delete(L, 4);
    printList(L);
    delete(L, 6);
    printList(L);

    return 0;
}