// 图的最小生成树 kruskal算法 
// 选最小边判断连通
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
    int start;
    int end;
    int weight;
}Edge;

Edge* initEdge(Graph* G){
    Edge* edge = (Edge*)malloc(sizeof(Edge) * G->arcNum);
    int index = 0;
    for(int i=0; i<G->vexNum; i++){
        for(int j=i+1; j<G->vexNum; j++){
            if(G->arcs[i][j] != MAX){
                edge[index].start = i;
                edge[index].end = j;
                edge[index].weight = G->arcs[i][j];
                index++;
            }
        }
    }
    return edge;
}

void sortEdge(Edge* edge, Graph* G){
    Edge temp;
    for(int i=0; i<G->arcNum-1; i++){
        for(int j=0; j<G->arcNum-i-1; j++){
            if(edge[j].weight > edge[j+1].weight){
                temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }
}

void kruskal(Graph* G){
    int* connected = (int*)malloc(sizeof(int) * G->vexNum);  //连通量
    for(int i=0; i<G->vexNum; i++){
        connected[i] = i;
    }
    Edge* edge = initEdge(G);  //边数组
    sortEdge(edge, G);
    for(int i=0; i<G->arcNum; i++){
        int start = connected[edge[i].start];  //起点连通量
        int end = connected[edge[i].end];  //终点连通量
        if(start != end){  //不为连通图时建立树
            printf("v%c --> v%c weight=%d\n", G->vexs[edge[i].start], G->vexs[edge[i].end], edge[i].weight);
            for(int j=0; j<G->vexNum; j++){
                if(connected[j] == end){  //终点与起点连通
                    connected[j] = start;
                }
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
        if(G->arcs[index][i]>0 && G->arcs[index][i]!=MAX && !visited[i]){  //存在边，未被访问
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
    kruskal(G);

    return 0;
}