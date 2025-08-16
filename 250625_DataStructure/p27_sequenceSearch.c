// 顺序查找
#include <stdio.h>
#include <stdlib.h>

typedef struct List{  //线性表
    int* data;
    int length;  //线性表长度
    int num;  //线性表中元素个数
}List;

List* initList(int length){  //初始化线性表
    List* list = (List*)malloc(sizeof(List));
    list->length = length;
    list->data = (int*)malloc(sizeof(int) * length);
    list->num = 0;
    return list;
}

void listAdd(List* list, int data){  //添加元素
    if(list->num + 1 <= list->length){
        list->data[list->num] = data;
        list->num = list->num + 1;
    }else{
        printf("Add failed: The list is full.\n");
    }
}

void listPrintf(List* list){  //打印线性表
    for(int i=0; i<list->num; i++){
        printf("%d -> ", list->data[i]);
    }
    printf("NULL\n");
}

int searchList(List* list, int key){  //顺序查找，返回索引
    for(int i=0; i<list->num; i++){
        if(list->data[i] == key){
            return i;
        }
    }
    return -1;
}


int main(){
    List* list = initList(5);
    listAdd(list, 1);
    listAdd(list, 2);
    listAdd(list, 3);
    listAdd(list, 4);
    listPrintf(list);
    printf("%d\n", searchList(list, 0));
    printf("%d\n", searchList(list, 1));
    printf("%d\n", searchList(list, 4));
    return 0;
}