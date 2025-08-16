// 图 邻阶矩阵
// BFS 广度优先遍历
// DFS 深度优先遍历
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph{
    char* vexs;  //点
    int** arcs;  //边 邻阶矩阵 二维数组
    int vexNum;  //点数
    int arcNum;  //边数
}Graph;

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
            if(G->arcs[i][j] != 0){ //计算边数
                G->arcNum ++;                
            }
        }
    }
    G->arcNum /= 2;  //无向图A-B/B-A是一条边
}

void DFS(Graph* G, int* visited, int index){  //深度搜索
    printf("%c ", G->vexs[index]);
    visited[index] = 1;  //当前深度已访问过
    for (int i=0; i<G->vexNum; i++){  //搜索当前点的所有边
        if(G->arcs[index][i]!=0 && !visited[i]){  //存在边，未被访问
            DFS(G, visited, i);  //对下一层进行搜索
        }
    }
}

//广度搜索，队列实现
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initQueue(){  //初始化
    Node* Q = (Node*)malloc(sizeof(Node));
    Q->data = 0;
    Q->next = NULL;
    return Q;
}

void enQueue(Node* Q, int data){  //入队
    Node* q = Q;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    while(q->next){
        q = q->next;
    }
    node->next = q->next;
    q->next = node;
    Q->data ++;
}

int isEmpty(Node* Q){
    if(Q->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int deQueue(Node* Q){  //出队
    if(isEmpty(Q)){
        return -1;
    }
    else{
        Node* node = Q->next;
        int data = node->data;
        Q->next = node->next;
        free(node);
        Q->data --;
        return data;
    }
}

void BFS(Graph* G, int* vistied, int index){
    printf("%c ", G->vexs[index]);
    vistied[index] = 1;
    Node* Q = initQueue();  //新建队列
    enQueue(Q, index);  //当前索引入队
    while(!isEmpty(Q)){  //队列不为空
        int i = deQueue(Q);  //出队
        for(int j=0; j<G->vexNum; j++){
            if(G->arcs[i][j]!=0 && !vistied[j]){
                printf("%c ", G->vexs[j]);
                vistied[j] = 1;
                enQueue(Q, j);
            }
        }
    }
}



int main(){
    Graph* G = initGraph(5);
    int arcs[5][5] = {
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
    /*
    (int*)arcs 将二维数组arcs强制转换为int型指针：
    在内存中，二维数组是按行优先顺序连续存储的
    这种转换通常用于将二维数组作为一维数组处理
    转换后可以通过指针算术访问所有25个元素
    */
    createGraph(G, "ABCDE", (int*)arcs);
    
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i=0; i<G->vexNum; i++){
        visited[i] = 0;
    }
    DFS(G, visited, 0);
    printf("\n");

    for(int i=0; i<G->vexNum; i++){
        visited[i] = 0;
    }
    BFS(G, visited, 0);
    printf("\n");
    return 0;
}