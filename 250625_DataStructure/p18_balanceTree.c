//平衡二叉树AVL
//一颗合理的二叉排序树
//左右子树高度不超过1
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    int height;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

int getHeight(TreeNode* node){
    return node ? node->height : 0;
}

int max(int a, int b){
    return a > b ? a : b;
}

void rrRotation(TreeNode* node, TreeNode** root){
    TreeNode* temp = node->rchild;  //保存中节点
    node->rchild = temp->lchild;  //中节点左子树连到父节点右子树
    temp->lchild = node;  //父节点连到中节点的左子树
    node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = max(getHeight(temp->lchild),getHeight(temp->rchild)) + 1;
    *root = temp;//中节点变根节点
}

void llRotation(TreeNode* node, TreeNode** root){
    TreeNode* temp = node->lchild;  //保存中节点
    node->lchild = temp->rchild;  //中节点右子树连到父节点左子树
    temp->rchild = node;  //父节点连到中节点的右子树
    node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = max(getHeight(temp->lchild),getHeight(temp->rchild)) + 1;
    *root = temp;//中节点变根节点
}

void avlInsert(TreeNode** T, int data){
    if(*T == NULL){
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->height = 0;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }else if (data < (*T)->data){
        avlInsert(&((*T)->lchild), data);
        //拿到当前节点左右子树的高度
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        //判断高度差
        if (lHeight - rHeight == 2){
            if(data < (*T)->lchild->data){  //LL调整
                llRotation(*T, T);  //传入根节点
            }else{  //LR调整，分解为先对左孩子RR，再对调整后的自己LL
                rrRotation((*T)->lchild, &((*T)->lchild));
                llRotation(*T, T);
            }
        }
    }else if (data > (*T)->data){
        avlInsert(&((*T)->rchild), data);
        //拿到当前节点左右子树的高度
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        //判断高度差
        if ((rHeight - lHeight) == 2){
            if(data > (*T)->rchild->data){  //RR调整
                rrRotation(*T, T);
            }else{  //RL调整
                llRotation((*T)->rchild, &((*T)->rchild));
                rrRotation(*T, T);
            }
        }
    }
    (*T)->height = max(getHeight((*T)->lchild), getHeight((*T)->rchild)) + 1;
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
    //int nums[5] = {1,2,3,4,5};
    //int nums[5] = {5,4,3,2,1};
    //int nums[5] = {8,7,9,5,6};
    int nums[5] = {1,8,6,7,10};
    for(int i=0; i<5; i++){
        avlInsert(&T, nums[i]);
    }
    preOrder(T);
    printf("\n");
}