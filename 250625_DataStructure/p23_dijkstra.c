// 图的最短路径 dijkstra算法
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

int getMin(int*d, int* s, int length){  //得到数组d里最小的值,s判断是否跳过，length数组长度
    int min = MAX;
    int index;
    for(int i=0; i<length; i++){
        if(d[i] < min && !s[i]){
            min = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(Graph* G, int index){
    //初始化s p d 数组
    int* s = (int*)malloc(sizeof(int) * G->vexNum);  //是否找到最短路径
    int* p = (int*)malloc(sizeof(int) * G->vexNum);  //前驱节点
    int* d = (int*)malloc(sizeof(int) * G->vexNum);  //路径长度
    for(int i=0; i<G->vexNum; i++){
        if(i == index){  //最短路径初始化
            s[i] = 1;
        }else{
            s[i] = 0;
        }
        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX){  //前驱和路径长度初始化
            p[i] = index;  //前驱是起点
            d[i] = G->arcs[index][i];
        }else{
            p[i] = -1;  //不相通没有前驱
            d[i] = MAX;
        }
        if(i==index){ //到自身最短路径0
            d[i] = 0;
        }
        //检查初始化结果
        //printf("s[%d]=%d, p[%d]=%d, d[%d]=%d\n",i,s[i],i,p[i],i,d[i]);
    }
    for(int i=0; i<G->vexNum-1; i++){  //更新到每个点最短路径，第一个点已经初始化，所有循环次数是-1
        index = getMin(d, s, G->vexNum);  //以最短的边作为下一个中转点
        s[index] = 1;
        for(int j=0; j<G->vexNum; j++){
            int minLen = d[index] + G->arcs[index][j];  //当前中转点的最短路径长度
            if(!s[j] && minLen<d[j]){  //更新最短路径
                d[j] = minLen;
                p[j] = index;  //前驱是中转点
            }
        }
    }
    for(int i=0; i<G->vexNum; i++){  //输出到每个点的最短路径
        printf("s[%d]=%d\tp[%d]=%d\td[%d]=%d\n",i,s[i],i,p[i],i,d[i]);
    }
}




int main(){
    Graph* G = initGraph(7);
    int arcs[7][7] = {
        0,12,MAX,MAX,MAX,16,14,
        12,0,10,MAX,MAX,7,MAX,
        MAX,10,0,3,5,6,MAX,
        MAX,MAX,3,0,4,MAX,MAX,
        MAX,MAX,5,4,0,2,8,
        16,7,6,MAX,2,0,9,
        14,MAX,MAX,MAX,8,9,0
    };
    createGraph(G, "1234567", (int*)arcs);
    
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i=0; i<G->vexNum; i++){
        visited[i] = 0;
    }
    DFS(G, visited, 0);
    printf("\n");
    dijkstra(G, 0);

    return 0;
}