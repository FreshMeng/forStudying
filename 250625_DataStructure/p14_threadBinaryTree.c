//中序线索二叉树

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

void inOrder(TreeNode* T){  //中序遍历普通二叉树
    if(T==NULL){
        return;
    }else{
        inOrder(T->lchild);
        printf("%c ", T->data);
        inOrder(T->rchild);
    }
}

void inThreadTree(TreeNode* T, TreeNode** pre){  //树中序线索化
    if(T){
        inThreadTree(T->lchild, pre);
        if(T->lchild==NULL){
            T->lchild = *pre;
            T->ltag = 1;
        }
        if((*pre)!=NULL && (*pre)->rchild==NULL){
            (*pre)->rchild = T;
            (*pre)->rtag = 1;
        }
        (*pre) = T;
        inThreadTree(T->rchild, pre);
    }
}

TreeNode* getFirst(TreeNode* T){  //中序线索树的顶点
    while(T->ltag == 0){
        T = T->lchild;
    }
    return T;
}

TreeNode* getNext(TreeNode* node){  //得到中序线索树下一个树
    if(node->rtag==1){
        return node->rchild;
    }else{
        return getFirst(node->rchild);
    }
}


int main(){
    TreeNode* T;
    int index = 0;
    TreeNode* pre = NULL;
    // createTree(&T,"ABD##EK###CF##G##",&index);
    createTree(&T,"ABDK###E##CF##G##",&index);
    inOrder(T);
    printf("\n");
    inThreadTree(T, &pre);
    pre->rchild = NULL;
    pre->rtag = 1;
    for (TreeNode* node = getFirst(T); node!=NULL; node=getNext(node)){
        printf("%c ", node->data);
    }
    printf("\n");

    return 0;
}