//B树的实现 插入
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{  //定义B树节点
    int level; //B树阶数
    int keyNum;  //关键字个数
    int childNum;  //孩子个数
    int* keys;  //关键字数组
    struct Node** children;  //孩子数组
    struct Node* parent;  //父指针
} Node;

Node* initNode(int level){  //初始化节点
    Node* node = (Node*)malloc(sizeof(Node));
    node->level = level;
    node->keyNum = 0;
    node->childNum = 0;
    node->keys = (int*)malloc(sizeof(int) * (level+1));
    node->children = (Node**)malloc(sizeof(Node*) * level);
    node->parent = NULL;
    int i;
    for(i = 0; i<level; i++){
        node->keys[i] = 0;
        node->children[i] = NULL;
    }
    node->keys[i] = 0;
    return node;
}

int findSutiteIndex(Node* node, int data){  //合适插入的索引
    int i;
    for(i=1; i<=node->keyNum; i++){
        if(data < node->keys[i]){
            break;
        }
    }
    return i;
}

Node* findSuiteLeafNode(Node* T, int data){  //合适插入的叶子节点
    if(T->childNum==0){
        return T;
    }else{
        int index = findSutiteIndex(T, data);
        return findSuiteLeafNode(T->children[index-1], data);
    }
}

void addData(Node* node, int data, Node** T){
    // 插入
    int index = findSutiteIndex(node, data);
    for(int i=node->keyNum; i>= index; i--){  //后移空出插入的位置
        node->keys[i+1] = node->keys[i];
    }
    node->keys[index] = data;
    node->keyNum++;
    // 判断分裂
    if(node->keyNum == node->level){
        // 左右分裂
        int mid = node->level / 2 + node->level % 2;  //中间索引
        Node* lchild = initNode(node->level);
        Node* rchild = initNode(node->level);
        for(int i=1; i<mid; i++){
            addData(lchild, node->keys[i], T);
        }
        for(int i=mid+1; i<=node->keyNum; i++){
            addData(rchild, node->keys[i], T);
        }
        // 孩子分到左右节点
        for(int i=0; i<mid; i++){  //左
            lchild->children[i] = node->children[i];
            if(node->children[i] != NULL){
                node->children[i]->parent = lchild;
                lchild->childNum++;
            }
        }
        int index = 0;  //右
        for(int i=mid; i<node->childNum; i++){
            rchild->children[index++] = node->children[i];
            if(node->children[i] != NULL){
                node->children[i]->parent = rchild;
                rchild->childNum ++;
            }
        }
        // 分裂后父节点的插入
        if(node->parent == NULL){  //原本无父节点，形成新的父节点
            Node* newParent = initNode(node->level);
            addData(newParent, node->keys[mid], T);
            newParent->children[0] = lchild;
            newParent->children[1] = rchild;
            newParent->childNum = 2;
            lchild->parent = newParent;
            rchild->parent = newParent;
            *T = newParent;
        }else{  //原本有父节点，插入到原本的父节点
            int index = findSutiteIndex(node->parent, node->keys[mid]);
            lchild->parent = node->parent;
            rchild->parent = node->parent;
            node->parent->children[index-1] = lchild;
            if(node->parent->children[index] != NULL){
                for(int i = node->parent->childNum - 1; i >= index; i--){
                    node->parent->children[i+1] = node->parent->children[i];
                }
            }
            node->parent->children[index] = rchild;
            node->parent->childNum++;
            addData(node->parent, node->keys[mid], T);
        }
    }
}

void insert(Node** T, int data){
    Node* node = findSuiteLeafNode(*T, data);
    addData(node, data, T);
}

void printTree(Node* T){
    if(T != NULL){
        for(int i=1; i<=T->keyNum; i++){
            printf("%d ", T->keys[i]);
        }
        printf("\n");
        for(int i = 0; i<T->childNum; i++){
            printTree(T->children[i]);
        }
    }
}

int main(){
    Node* T = initNode(5);
    insert(&T, 1);
    insert(&T, 2);
    insert(&T, 3);
    insert(&T, 4);
    insert(&T, 5);
    insert(&T, 6);
    insert(&T, 7);
    insert(&T, 8);
    insert(&T, 9);
    insert(&T, 10);
    insert(&T, 11);
    insert(&T, 12);
    insert(&T, 13);
    insert(&T, 14);
    insert(&T, 15);
    printTree(T);

    return 0;
}