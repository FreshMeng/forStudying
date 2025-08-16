//前序线索二叉树

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int ltag;  //左指针为0，指向子树，为1，指向线索
    int rtag;
}TreeNode;

void createTree(TreeNode** T, char* ch, int* index){
    char data = ch[*index];
    *index += 1;
    if(data == '#'){
        (*T) = NULL;
    }else{
        (*T) = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->ltag = 0;
        (*T)->rtag = 0;
        createTree(&((*T)->lchild), ch, index);
        createTree(&((*T)->rchild), ch, index);
    }
}

void preOrder(TreeNode* T){  //前序遍历普通二叉树
    if(T==NULL){
        return;
    }else{
        printf("%c ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void preThreadTree(TreeNode* T, TreeNode** pre){  //树前序线索化
    if(T){
        if(T->lchild==NULL){
            T->lchild = *pre;
            T->ltag = 1;
        }
        if((*pre)!=NULL && (*pre)->rchild==NULL){
            (*pre)->rchild = T;
            (*pre)->rtag = 1;
        }
        (*pre) = T;
        if (T->ltag == 0){  //上面已经改变左子树的指针，判断是否原本有左子树
            preThreadTree(T->lchild, pre);}
        if (T->rtag == 0){  //右子树同理，在上一次递归中可能改变右子树指针
            preThreadTree(T->rchild, pre);}
    }
}

TreeNode* getNext(TreeNode* node){  //得到前序线索树下一个树
    if(node->rtag==1){
        return node->rchild;
    }else{
        if (node->ltag == 0){
            return node->lchild;
        }else{
            return node->rchild;
        }
    }
}


int main(){
    TreeNode* T;
    int index = 0;
    TreeNode* pre = NULL;
    //createTree(&T,"ABD##E##CF##G##",&index);
    //createTree(&T,"AB##C##",&index);
    createTree(&T,"ABDK###E##C##",&index);
    preOrder(T);
    printf("\n");
    preThreadTree(T, &pre);
    pre->rchild = NULL;
    pre->rtag = 1;
    for (TreeNode* node = T; node!=NULL; node=getNext(node)){
        printf("%c ", node->data);
    }
    printf("\n");

    return 0;
}