//图的关键路径
//1.有向图的拓扑排序
//2.
#include <stdio.h>
#include <stdlib.h>

// 图顶点之前不通，邻阶矩阵的值为MAX
// 如果顶点是自己本身，那么值为0
#define MAX 65535

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
            if(G->arcs[i][j]>0 && G->arcs[i][j]!=MAX){
                inDegrees[j]++;  //入度是指向那个节点的边数
            }
        }
    }
    return inDegrees;
}

int* topologicalSort(Graph* G){  //拓扑排序
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
        int vex = pop(stack);
        top[index++] = vex;
        for(int i=0; i<G->vexNum; i++){  //更新入度
            if(G->arcs[vex][i]>0 && G->arcs[vex][i] != MAX){  //出栈点起点当前点终点
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
    return top;
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
            if(G->arcs[i][j] > 0 && G->arcs[i][j] != MAX){ //计算边数
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

int getIndex(int* top, int vexNum, int j){  //获取点在拓扑排序中的索引
    int i;
    for(i=0; i<vexNum; i++){
        if(top[i] == j){
            break;
        }
    }
    return i;
}

void criticalPath(Graph* G){  //关键路径
    //1.拓扑排序
    int* top = topologicalSort(G);
    //2.1.节点最早时间
    int* early = (int*)malloc(sizeof(int) * G->vexNum);  //最早时间数组
    int* late = (int*)malloc(sizeof(int) * G->vexNum);  //最晚时间数组
    for(int i=0; i<G->vexNum; i++){  //初始化
        early[i] = 0;
        late[i] = 0;
    }
    for(int i=0; i<G->vexNum; i++){  //计算最早时间,top[i]是终点
        int max = 0;
        int index;
        for(int j=0; j<G->vexNum; j++){  //找边
            if(G->arcs[j][top[i]]>0 && G->arcs[j][top[i]]!=MAX){  //边存在
                index = getIndex(top, G->vexNum, j);  //按拓扑排序推时间
                if(early[index] + G->arcs[j][top[i]] > max){  //找 前驱最小+当前边 的最大值
                    max = early[index] + G->arcs[j][top[i]];
                }
            }
        }
        early[i] = max;
    }
    for(int i=0; i<G->vexNum; i++){  //验证
            printf("%d ", early[i]);
        }
    printf("\n");
    //2.2. 计算最晚时间
    late[G->vexNum-1] = early[G->vexNum-1];  //最后一个节点，最早和最晚时间相同
    for(int i=G->vexNum-2; i>=0; i--){  //计算最晚时间,top[i]是起点
        int min = 65536;
        int index;
        for(int j=0; j<G->vexNum; j++){  //找边
            if(G->arcs[top[i]][j]>0 && G->arcs[top[i]][j]!=MAX){  //边存在
                index = getIndex(top, G->vexNum, j);  //按拓扑排序推时间
                if(late[index] - G->arcs[top[i]][j] < min){  //找 后驱最小-当前边 的最小值
                    min = late[index] - G->arcs[top[i]][j];
                }
            }
        }
        late[i] = min;
    }
    for(int i=0; i<G->vexNum; i++){  //验证
            printf("%d ", late[i]);
        }
    printf("\n");
    //3.边时间间隔等于0
    for(int i=0; i<G->vexNum; i++){
        for(int j=0; j<G->vexNum; j++){
            if(G->arcs[i][j]>0 && G->arcs[i][j]!=MAX){  //顺序找边
                int start = getIndex(top, G->vexNum, i);
                int end = getIndex(top, G->vexNum, j);
                if(late[end] - G->arcs[i][j] - early[start] == 0){  //间隔为0
                    printf("v%c --> v%c\n", G->vexs[i], G->vexs[j]);
                }
            }
        }
    }

}

int main(){
    Graph* G = initGraph(9);
    int arcs[9][9] = {
        0,6,4,5,MAX,MAX,MAX,MAX,MAX,
        MAX,0,MAX,MAX, 1, MAX,MAX,MAX,MAX,
        MAX,MAX,0,MAX,1,MAX,MAX,MAX,MAX,
        MAX,MAX,MAX,0,MAX,2,MAX,MAX,MAX,
        MAX,MAX,MAX,MAX,0,MAX,9,7,MAX,
        MAX,MAX,MAX,MAX,MAX,0,MAX,4,MAX,
        MAX,MAX,MAX,MAX,MAX,MAX,0,MAX,2,
        MAX,MAX,MAX,MAX,MAX,MAX,MAX,0,4,
        MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,0
    };
    createGraph(G, "012345678", (int*)arcs);
    
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i=0; i<G->vexNum; i++){
        visited[i] = 0;
    }
    DFS(G, visited, 0);
    printf("\n");
    //topologicalSort(G);
    criticalPath(G);

    return 0;
}