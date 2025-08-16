//栈
//一种特殊的链表，只在一端操作，先进后出
//通过链表头插实现
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initStack(){  //初始化栈
    Node* S = (Node*)malloc(sizeof(Node));
    S->data = 0;
    S->next = NULL;
}

int isEmpty(Node* S){  //判断栈空
    if(S->data==0 || S->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int getTop(Node* S){  //栈顶元素
    if(isEmpty(S)){
        return -1;
    }
    else{
        return S->next->data;
    }
}

int pop(Node* S){  //栈顶元素
    if(isEmpty(S)){
        return -1;
    }
    else{
        Node* node = S->next;
        int data = node->data;
        S->next = node->next;
        free(node);
        S->data --;
        return data;
    }
}

void push(Node* S, int data){  //入栈
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = S->next;
    S->next = node;
    S->data ++;
}

void printStack(Node* S){
    Node* node = S->next;
    while(node){
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


int main(){
    Node* S = initStack();
    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 4);
    push(S, 5);
    printStack(S);
    int i = pop(S);
    printf("current elem = %d\n", i);
    printStack(S);
    return 0;
}