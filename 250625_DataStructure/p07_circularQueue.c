//循环队列
//有限的循环队列，数组实现

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct Queue{
    int front;  //头下标
    int rear;  //尾下标
    int data[MAXSIZE];  //队列数组
}Queue;

Queue* initQueue(){  //初始化
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

int isFull(Queue* Q){  //是否队满
    if ((Q->rear+1) % MAXSIZE == Q->front){  //尾下标+1后等于头下标，队列满；通过余数让下标循环
        return 1;
    }
    else{
        return 0;
    }
}

int enQueue(Queue* Q, int data){  //入队
    if(isFull(Q)){
        return 0;
    }
    else{
        Q->data[Q->rear] = data;
        Q->rear = (Q->rear+1) % MAXSIZE;
        return 1;
    }
}

int isEmpty(Queue* Q){  //判断队空
    if(Q->front == Q->rear){  //头尾相同时为空
        return 1;
    }
    else{
        return 0;
    }
}

int deQueue(Queue* Q){  //出队
    if(isEmpty(Q)){
        return -1;
    }
    else{
        int data = Q->data[Q->front];
        Q->front = (Q->front+1) % MAXSIZE;  //头坐标变化，余数让坐标在0~MAXSIZE-1内变化
        return data;
    }
}

void printQueue(Queue* Q){  //遍历
    int length = (Q->rear - Q->front + MAXSIZE) % MAXSIZE;  //队列长度，
    int index = Q->front;  //从头到尾
    for(int i=0; i<length; i++){
        printf("%d->", Q->data[index]);
        index = (index + 1) % MAXSIZE;
    }
    printf("NULL\n");
}

int main(){
    Queue* Q = initQueue();
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    printQueue(Q);
    deQueue(Q);
    printQueue(Q);
    deQueue(Q);
    printQueue(Q);

    return 0;
}