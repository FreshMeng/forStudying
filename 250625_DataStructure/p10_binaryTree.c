//二叉树遍历

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lChild;
    struct TreeNode* rChild;
}TreeNode;

void createTree(TreeNode** T, char* ch, int* index){
    char data = ch[*index];
    *index += 1;
    if(data=='#'){
        *T = NULL;
    }
    else{
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        createTree(&((*T)->lChild), ch, index);
        createTree(&((*T)->rChild), ch, index);
    }
}

void preOrder(TreeNode* T){  //前序遍历
    if(T == NULL){
        return;
    }
    else{
        printf("%c", T->data);
        preOrder(T->lChild);
        preOrder(T->rChild);
    }
}

void inOrder(TreeNode* T){  //中序遍历
    if(T == NULL){
        return;
    }
    else{
        inOrder(T->lChild);
        printf("%c", T->data);
        inOrder(T->rChild);
    }
}

void postOrder(TreeNode* T){  //后序遍历
    if(T == NULL){
        return;
    }
    else{
        postOrder(T->lChild);
        postOrder(T->rChild);
        printf("%c", T->data);
    }
}

int main(){
    TreeNode* T;
    int index = 0;
    createTree(&T,"abd##e##cf##g##", &index);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");
    
    return 0;
}