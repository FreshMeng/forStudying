//队列
//特殊的线性表，只允许在一端进行存取
//链表尾插头出

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initQueue(){  //初始化
    Node* Q = (Node*)malloc(sizeof(Node));
    Q->data = 0;
    Q->next = NULL;
    return Q;
}

void enQueue(Node* Q, int data){  //入队
    Node* q = Q;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    while(q->next){
        q = q->next;
    }
    node->next = q->next;
    q->next = node;
    Q->data ++;
}

int isEmpty(Node* Q){
    if(Q->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int deQueue(Node* Q){
    if(isEmpty(Q)){
        return -1;
    }
    else{
        Node* node = Q->next;
        int data = node->data;
        Q->next = node->next;
        free(node);
        Q->data --;
        return data;
    }
}

void printQueue(Node* Q){  //出队
    Node* node = Q->next;
    while(node){
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    Node* Q = initQueue();
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    printQueue(Q);
    int data = deQueue(Q);
    printf("%d\n", data);
    printQueue(Q);
    deQueue(Q);
    printQueue(Q);
    deQueue(Q);
    printQueue(Q);
    deQueue(Q);
    printQueue(Q);
    deQueue(Q);
    printQueue(Q);
    return 0;
}