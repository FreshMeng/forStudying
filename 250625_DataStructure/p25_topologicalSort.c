//图的拓扑排序

// 图的最短路径 floyd算法
#include <stdio.h>
#include <stdlib.h>

// 图顶点之前不通，邻阶矩阵的值为MAX
// 如果顶点是自己本身，那么值为0
#define MAX 23767

typedef struct Graph{
    char* vexs;  //点
    int** arcs;  //边 邻阶矩阵 二维数组
    int vexNum;  //点数
    int arcNum;  //边数
}Graph;

typedef struct Node{  //链表
    int data;
    struct Node* next;
}Node;

Node* initStack(){  //栈
    Node* stack = (Node*)malloc(sizeof(Node));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}

void push(Node* stack, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->next;
    stack->next = node;
    stack->data++;
}

int isEmpty(Node* stack){
    if(stack->next==NULL){
        return 1;
    }else{
        return 0;
    }
}

int pop(Node* stack){
    if(!isEmpty(stack)){
        Node* node = stack->next;
        stack->next = node->next;
        return node->data;
    }else{
        return -1;
    }
}

int* findInDegrees(Graph* G){  //求入度
    int* inDegrees = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i=0; i<G->vexNum; i++){  //初始化数组
        inDegrees[i] = 0;
    }
    for(int i=0; i<G->vexNum; i++){
        for(int j=0; j<G->vexNum; j++){
            if(G->arcs[i][j]){
                inDegrees[j]++;  //入度是指向那个节点的边数
            }
        }
    }
    return inDegrees;
}

void topologicalSort(Graph* G){
    int index = 0;  //top的索引
    int* top = (int*)malloc(sizeof(int) * G->vexNum);  //记录排序的序列
    int* inDegrees = findInDegrees(G);
    Node* stack = initStack();
    for(int i=0; i<G->vexNum; i++){
        if(inDegrees[i] == 0){
            push(stack, i);
        }
    }
    while(!isEmpty(stack)){
        top[index++] = pop(stack);
        for(int i=0; i<G->vexNum; i++){  //更新入度
            if(G->arcs[top[index-1]][i]){  //出栈点起点当前点终点
                inDegrees[i]--;  //有边则入度减少
                if(inDegrees[i] == 0){
                    push(stack, i);
                }
            }
        }
    }
    for(int i=0; i<G->vexNum; i++){
        printf("%c ", G->vexs[top[i]]);
    }
    printf("\n");
}

Graph* initGraph(int vexNum){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->vexs = (char*)malloc(sizeof(char) * vexNum);
    G->arcs = (int**)malloc(sizeof(int*) * vexNum);
    for (int i=0; i<vexNum; i++){
        G->arcs[i] = (int*)malloc(sizeof(int) * vexNum);  //二级指针指向一级指针
    }
    G->vexNum = vexNum;
    G->arcNum = 0;
    return G;
}

void createGraph(Graph* G, char* vexs, int* arcs){
    for(int i=0; i<G->vexNum; i++){
        G->vexs[i] = vexs[i];
        for(int j=0; j<G->vexNum; j++){
            G->arcs[i][j] = *(arcs + i*(G->vexNum) + j);
            if(G->arcs[i][j] != 0 && G->arcs[i][j] != MAX){ //计算边数
                G->arcNum ++;                
            }
        }
    }
    //G->arcNum /= 2;  //有向图没有重复边
}

void DFS(Graph* G, int* visited, int index){  //深度搜索
    printf("%c ", G->vexs[index]);
    visited[index] = 1;  //当前深度已访问过
    for (int i=0; i<G->vexNum; i++){  //搜索当前点的所有边
        if(G->arcs[index][i]>0 && G->arcs[index][i]!=MAX && !visited[i]){  //存在边，未被访问
            DFS(G, visited, i);  //对下一层进行搜索
        }
    }
}

int main(){
    Graph* G = initGraph(6);
    int arcs[6][6] = {
        0,1,1,1,0,0,
        0,0,0,0,0,0,
        0,1,0,0,1,0,
        0,0,0,0,1,0,
        0,0,0,0,0,0,
        0,0,0,1,1,0
    };
    createGraph(G, "123456", (int*)arcs);
    
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i=0; i<G->vexNum; i++){
        visited[i] = 0;
    }
    DFS(G, visited, 0);
    printf("\n");
    topologicalSort(G);

    return 0;
}