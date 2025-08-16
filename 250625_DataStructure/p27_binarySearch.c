// 二分查找
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

int binarySerach(List* list, int key){  //二分查找，返回索引
    int start = 0;  //起始索引
    int end = list->num - 1;  //结束索引
    int mid ;  //中间索引
    while(start <= end){
        mid = (start+end)/2;
        if(list->data[mid] > key){
            end = mid - 1;
        }else if(list->data[mid] < key){
            start = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int binarySearchRecursion(int key, List* list, int start, int end){
    if(start == end){  //退出条件
        if(list->data[start] == key){
            return start;
        }else{
            return -1;
        }
    }
    int mid = (start + end) / 2;
    if(list->data[mid] < key){
        return binarySearchRecursion(key, list, mid+1, end);
    }else if(list->data[mid] > key){
        return binarySearchRecursion(key, list, start, mid-1);
    }else{
        return mid;
    }
}


int main(){
    List* list = initList(9);
    listAdd(list, 1);
    listAdd(list, 2);
    listAdd(list, 3);
    listAdd(list, 4);
    listAdd(list, 5);
    listAdd(list, 6);
    listAdd(list, 7);
    listAdd(list, 8);
    listAdd(list, 9);
    listPrintf(list);

    // printf("%d\n", binarySerach(list, 0));
    // printf("%d\n", binarySerach(list, 10));
    // printf("%d\n", binarySerach(list, 1));
    // printf("%d\n", binarySerach(list, 4));
    // printf("%d\n", binarySerach(list, 8));

    printf("%d\n", binarySearchRecursion(0, list, 0, 8));
    printf("%d\n", binarySearchRecursion(10, list, 0, 8));
    printf("%d\n", binarySearchRecursion(1, list, 0, 8));
    printf("%d\n", binarySearchRecursion(4, list, 0, 8));
    printf("%d\n", binarySearchRecursion(8, list, 0, 8));

    return 0;
}