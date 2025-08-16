// 二叉排序树BST
// 左子树都比根节点小，右子树都比根节点大

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

TreeNode* bstSearch(TreeNode* T, int key){  //排序树查找
    if(T){
        if(T->data == key){
            return T;
        }else if(T->data < key){
            return bstSearch(T->rchild, key);
        }else if(T->data > key){
            return bstSearch(T->lchild, key);
        }
    }else{
        return NULL;
    }
}

void bstInsert(TreeNode** T, int data){
    if((*T) == NULL){
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;        
    }else if(data == (*T)->data){
        return;
    }else if(data < (*T)->data){
        bstInsert(&((*T)->lchild), data);
    }else if(data > (*T)->data){
        bstInsert(&((*T)->rchild), data);
    }
}

void preOrder(TreeNode* T){
    if(T){
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

int main(){
    TreeNode* T = NULL;
    //int nums[6] = {4,5,19,23,2,8};
    int nums[6] = {8,6,10,9,11,23};
    for(int i=0; i<6; i++){
        bstInsert(&T, nums[i]);
    }
    preOrder(T);
    printf("\n");
    TreeNode* T2 = bstSearch(T, 9);
    printf("%d\n", T2->data);
}
