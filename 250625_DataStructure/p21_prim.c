// 图的最小生成树 prim算法
// 记录U集合的状态
// 选择最小边和点加入到集合
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

typedef struct Edge{  //边数组
    char vex;  //记录U集合到最小边的起始节点
    int weight;  //记录最小边
}Edge;

// 当edge.weight=0时，代表顶点加入U集合中
Edge* initEdge(Graph* G, int index){
    Edge* edge = (Edge*)malloc(sizeof(Edge) * G->vexNum);
    for (int i=0; i<G->vexNum; i++){
        edge[i].vex = G->vexs[index];
        edge[i].weight = G->arcs[index][i];
    }
    return edge;
}

int getMinEdge(Edge* edge, Graph* G){
    int index;  //最小边索引
    int min = MAX;  //最小边的值
    for(int i=0; i<G->vexNum; i++){
        if(edge[i].weight!=0 && min>edge[i].weight){
            min = edge[i].weight;
            index = i;
        }
    }
    return index;
}

void prim(Graph* G, int index){
    int min;
    Edge* edge = initEdge(G, index);
    for(int i=0; i<G->vexNum-1; i++){
        min = getMinEdge(edge, G);  //最小边的索引
        printf("v%c --> v%c, weight=%d\n", edge[min].vex, G->vexs[min], edge[min].weight);
        edge[min].weight = 0;  //点加入U集合
        for(int j=0; j<G->vexNum; j++){  //更新min的边
            if(G->arcs[min][j] < edge[j].weight){
                edge[j].weight = G->arcs[min][j];
                edge[j].vex = G->vexs[min];
            }
        }        
    }
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
    G->arcNum /= 2;  //无向图A-B/B-A是一条边
}

void DFS(Graph* G, int* visited, int index){  //深度搜索
    printf("%c ", G->vexs[index]);
    visited[index] = 1;  //当前深度已访问过
    for (int i=0; i<G->vexNum; i++){  //搜索当前点的所有边
        if(G->arcs[index][i]>=0 && G->arcs[index][i]!=MAX && !visited[i]){  //存在边，未被访问
            DFS(G, visited, i);  //对下一层进行搜索
        }
    }
}




int main(){
    Graph* G = initGraph(6);
    int arcs[6][6] = {
        0,6,1,5,MAX,MAX,
        6,0,5,MAX,3,MAX,
        1,5,0,5,6,4,
        5,MAX,5,0,MAX,2,
        MAX,3,6,MAX,0,6,
        MAX,MAX,4,2,6,0
    };
    createGraph(G, "123456", (int*)arcs);
    
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i=0; i<G->vexNum; i++){
        visited[i] = 0;
    }
    DFS(G, visited, 0);
    printf("\n");

    prim(G,0);

    return 0;
}