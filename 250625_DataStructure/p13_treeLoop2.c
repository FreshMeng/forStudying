//循环实现二叉树后序遍历
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int flag;  //是否被访问过
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
        (*T)->flag = 0;
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

TreeNode* getTop(StackNode* S){  //获得栈顶元素
    if(isEmpty(S)){
        return NULL;
    }else{
        StackNode* node = S->next;
        return node->data;
    }
}

void postOrder(TreeNode* T){  //后序遍历
    TreeNode* node = T;
    StackNode* s = initStack();
    TreeNode* top;  //用于记录栈顶元素
    while(node || !isEmpty(s)){
        if(node){  //最左入栈
            push(node, s);
            node = node->lchild;
        }else{
            top = getTop(s);  //判断栈顶是否有右子树
            if(top->rchild && top->rchild->flag==0){
                top = top->rchild;  //入栈右子树
                push(top, s);
                node = top->lchild;  //循环入栈最左
            }else{
                top = pop(s);
                top->flag = 1;  //被访问过标记
                printf("%c ", top->data);
            }
        }
    }
}


int main(){
    TreeNode* T ;
    int index = 0;
    createTree(&T, "ABD#F##E##C##", &index);
    postOrder(T);
    printf("\n");

    return 0;
}