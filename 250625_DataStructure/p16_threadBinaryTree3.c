//后序线索二叉树

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    struct TreeNode* parent;  //后序线索遍历时用到的父亲指针
    int ltag;  //左指针为0，指向子树，为1，指向线索
    int rtag;
}TreeNode;

void createTree(TreeNode** T, char* ch, int* index, TreeNode* parent){
    char data = ch[*index];
    *index += 1;
    if(data == '#'){
        (*T) = NULL;
    }else{
        (*T) = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->ltag = 0;
        (*T)->rtag = 0;
        (*T)->parent = parent;
        createTree(&((*T)->lchild), ch, index, *T);
        createTree(&((*T)->rchild), ch, index, *T);
    }
}

void postOrder(TreeNode* T){  //前序遍历普通二叉树
    if(T==NULL){
        return;
    }else{
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c ", T->data);
    }
}

void postThreadTree(TreeNode* T, TreeNode** pre){  //树前序线索化
    if(T){
        postThreadTree(T->lchild, pre);
        postThreadTree(T->rchild, pre);
        if(T->lchild==NULL){
            T->lchild = *pre;
            T->ltag = 1;
        }
        if((*pre)!=NULL && (*pre)->rchild==NULL){
            (*pre)->rchild = T;
            (*pre)->rtag = 1;
        }
        (*pre) = T;
    }
}

TreeNode* getFirst(TreeNode* T){  //得到后序的头
    while(T->ltag == 0){
        T = T->lchild;
    }
    if(T->rtag == 0){
        return getFirst(T->rchild);  //加return,在此结束，防止后续输出
    }
    return T;
}

TreeNode* getNext(TreeNode* node){  //得到后序线索树下一个树
    // 1.是根节点
    // 2.是左孩子，有右孩子
    // 3.是左孩子，无右孩子，或者是右孩子
    if(node->rtag==1){
        return node->rchild;
    }else if(node->parent == NULL){  //1.是根节点
        return NULL;
    }else if(node->parent->rchild == node){  //2.是右孩子
        return node->parent;
    }else if(node->parent->rtag==0){  //3.是左孩子,有右孩子
        return getFirst(node->parent->rchild);
    }else {  //是左孩子，无右孩子
        return node->parent;
    }
}


int main(){
    TreeNode* T;
    int index = 0;
    TreeNode* pre = NULL;
    //createTree(&T,"ABD##E##CF##G##",&index);
    //createTree(&T,"AB##C##",&index, NULL);
    createTree(&T,"ABD#F##E##C##",&index, NULL);
    postOrder(T);
    printf("\n");
    postThreadTree(T, &pre);
    for (TreeNode* node = getFirst(T); node!=NULL; node=getNext(node)){
        printf("%c ", node->data);
    }
    printf("\n");

    return 0;
}