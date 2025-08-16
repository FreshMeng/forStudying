// 二叉树遍历非递归实现
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

typedef struct StackNode{
    TreeNode* data;
    struct StackNode* next;
}StackNode;

void createTree(TreeNode** T, char* data, int* index){
    char ch = data[*index];
    *index += 1;
    if (ch=='#'){
        *T = NULL;
    }else{
        (*T) = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&((*T)->lchild), data, index);
        createTree(&((*T)->rchild), data, index);
    }
}

StackNode* initStack(){
    StackNode* S = (StackNode*)malloc(sizeof(StackNode));
    S->data = NULL;
    S->next = NULL;
    return S;
}

void push(TreeNode* data, StackNode* S){  //入栈，头插法
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = S->next;
    S->next = node;
}

int isEmpty(StackNode* S){  //判断栈空
    if(S->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

TreeNode* pop(StackNode* S){  //出栈
    if(isEmpty(S)){
        return NULL;
    }else{
        StackNode* node = S->next;
        S->next = node->next;
        return node->data;
    }
}

void preOrder(TreeNode* T){
    TreeNode* node = T;
    TreeNode* nodePop;
    StackNode* S = initStack();
    while(node || !(isEmpty(S))){
        if (node){
            printf("%c ", node->data);
            push(node, S);
            node = node->lchild;
        }else{
            node = pop(S);
            node = node->rchild;
        }
    }
}

void inOrder(TreeNode* T){
    TreeNode* node = T;
    TreeNode* nodePop;
    StackNode* S = initStack();
    while(node || !(isEmpty(S))){
        if (node){
            push(node, S);
            node = node->lchild;
        }else{
            node = pop(S);
            printf("%c ", node->data);
            node = node->rchild;
        }
    }
}

int main(){
    TreeNode* T ;
    int index = 0;
    createTree(&T, "ABD##E##CF##G##", &index);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");

    return 0;
}