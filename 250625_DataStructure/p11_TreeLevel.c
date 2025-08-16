// 树的层次遍历

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{  //定义树
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

typedef struct QueueNode{  //定义队
    TreeNode* data;
    struct QueueNode* pre;
    struct QueueNode* next;
}QueueNode;

void createTree(TreeNode** T, char* data, int* index){  //创建树
    char ch = data[*index];
    *index += 1;
    if(ch=='#'){
        *T = NULL;
    }else{
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&((*T)->lchild), data, index);
        createTree(&((*T)->rchild), data, index);
    }
}

QueueNode* initQueue(){  //初始化队
    QueueNode* Q = (QueueNode*)malloc(sizeof(QueueNode));
    Q->data = NULL;
    Q->next = Q;
    Q->pre = Q;
    return Q;
}

void enQueue(TreeNode* data, QueueNode* Q){  //入队
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = Q;
    node->pre = Q->pre;
    Q->pre->next = node;
    Q->pre = node;
}

int isEmpty(QueueNode* Q){  //判断队空
    if (Q->next == Q){
        return 1;
    }else{
        return 0;
    }
}

QueueNode* deQueue(QueueNode* Q){  //出队
    if (isEmpty(Q)){
        return NULL;
    }else{
        QueueNode* node = Q->next;
        node->next->pre = Q;
        Q->next = node->next;
        return node;
    }
}

void LevelTraverse(QueueNode* Q, TreeNode* T){  //层次遍历
    enQueue(T, Q);  //树入队
    while(!isEmpty(Q)){  //是否有子树
        QueueNode* node = deQueue(Q);  //第一个树出队
        printf("%c ", node->data->data);  //打印树的值
        if(node->data->lchild){  //出队的树是否有孩子
            enQueue(node->data->lchild, Q);  //孩子入队
        }
        if(node->data->rchild){
            enQueue(node->data->rchild, Q);
        }
    }
}


int main(){
    TreeNode* T;
    int index = 0;
    QueueNode* Q = initQueue();
    createTree(&T, "ABD##E##CF##G##", &index);
    LevelTraverse(Q, T);
    printf("\n");

    return 0;
}