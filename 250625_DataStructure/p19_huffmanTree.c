//哈夫曼树，路径权重最小
//用于二进制压缩，权重越大编码越短
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int weight;
    int parent;
    int lchild;
    int rchild;
}TreeNode;

typedef struct HFTree{
    TreeNode* data;
    int length;
}HFTree;

HFTree* initTree(int* weight, int length){
    HFTree* T = (HFTree*)malloc(sizeof(HFTree));
    T->data = (TreeNode*)malloc(sizeof(TreeNode)*(2*length-1));
    T->length = length;
    for(int i=0; i<length; i++){
        T->data[i].weight = weight[i];
        T->data[i].parent = 0;
        T->data[i].lchild = -1;
        T->data[i].rchild = -1;
    }
    return T;
}

int* selectMin(HFTree* T){  //找两个最小权重
    int min = 10000;  //最小
    int secondMin = 10000;  //次小
    int minIndex;
    int secondIndex;
    for(int i=0; i<T->length; i++){  //寻找最小
        if(T->data[i].parent == 0){  //没有父节点
            if(T->data[i].weight < min){
                min = T->data[i].weight;
                minIndex = i;
            }
        }
    }
    for(int i=0; i<T->length; i++){  //寻找次小
        if(T->data[i].parent == 0 && i!=minIndex){  //没有父节点
            if(T->data[i].weight < secondMin){
                secondMin = T->data[i].weight;
                secondIndex = i;
            }
        }
    }
    int* res = (int*)malloc(sizeof(int)*2);
    res[0] = minIndex;
    res[1] = secondIndex;
    return res;
}

void createHFTree(HFTree* T){
    int* res;
    int min;  //最小索引
    int secondMin;  //次小索引
    int length = T->length*2 - 1;
    for(int i=T->length; i<length; i++){  //创建空气节点
        res = selectMin(T);
        min = res[0];
        secondMin = res[1];
        T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
        T->data[i].lchild = min;
        T->data[i].rchild = secondMin;
        T->data[i].parent = 0;  //当前无父节点，用于selectMin()的判断
        T->data[min].parent = i;
        T->data[secondMin].parent = i;
        T->length ++;
    }
}

void preOrder(HFTree* T, int index){
    if(index != -1){
        printf("%d ", T->data[index].weight);
        preOrder(T, T->data[index].lchild);
        preOrder(T, T->data[index].rchild);
    }
}


int main(){
    //int weight[4] = {1,2,3,4};
    //HFTree* T = initTree(weight, 4);
    int weight[7] = {5,1,3,6,11,2,4};
    HFTree* T = initTree(weight, 7);
    createHFTree(T);
    preOrder(T, T->length-1); //根节点是最后一个节点
    printf("\n");
    return 0;
}