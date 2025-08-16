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

void floyd(Graph* G){  //
    int d[G->vexNum][G->vexNum];  //最短路径数组
    int p[G->vexNum][G->vexNum];  //前驱数组
    //初始化d p
    for(int i=0; i<G->vexNum; i++){
        for(int j=0; j<G->vexNum; j++){
            d[i][j] = G->arcs[i][j];
            if(d[i][j]>0 && d[i][j]!=MAX){  //有边
                p[i][j] = i;
            }else{  //无边
                p[i][j] = -1;
            }
        }
    }
    //更新d p
    for(int i=0; i<G->vexNum; i++){  //中转点
        for(int j=0; j<G->vexNum; j++){  //起点
            for(int k=0; k<G->vexNum; k++){  //终点
                if(d[j][i] + d[i][k] < d[j][k]){  //中转更短时
                    d[j][k] = d[j][i] + d[i][k];  //更新最短路径
                    p[j][k] = p[i][k];  //更新前驱
                }
            }
        }
    }
    //输出d p
    for(int i=0; i<G->vexNum; i++){
        for(int j=0; j<G->vexNum; j++){
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<G->vexNum; i++){
        for(int j=0; j<G->vexNum; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}






int main(){
    Graph* G = initGraph(4);
    int arcs[4][4] = {
        0,1,MAX,3,
        1,0,2,2,
        MAX,2,0,8,
        3,2,8,0
    };
    createGraph(G, "1234", (int*)arcs);
    
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i=0; i<G->vexNum; i++){
        visited[i] = 0;
    }
    //DFS(G, visited, 0);
    printf("\n");
    floyd(G);

    return 0;
}