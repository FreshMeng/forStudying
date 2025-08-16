//单链表
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initList(){  //初始化
    Node* list = (Node*)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    return list;
}

void headInsert(Node* list, int data){  //头插
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = list->next;
    list->next = node;
    list->data++;
}

void tailInsert(Node* list, int data){  //尾插
    Node* list2 = list;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    while(list2->next){
        list2 = list2->next;
    }
    list2->next = node;
    list->data++;
}

void deleteList(Node* list, int data){  //删除
    Node* pre = list;
    Node* current = list->next;
    while(current){
        if(current->data == data){
            pre->next = current->next;
            free(current);
            break;
        }
        pre = current;
        current = current->next;
    }
    list->data--;
}

void printList(Node* list){  //遍历
    list = list->next;
    while(list){
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main(){
    Node* list = initList();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    tailInsert(list, 4);
    tailInsert(list, 5);
    tailInsert(list, 6);
    headInsert(list, 7);
    headInsert(list, 8);
    headInsert(list, 9);
    printList(list);
    deleteList(list, 1);
    printList(list);
    deleteList(list, 9);
    printList(list);
    deleteList(list, 6);
    printList(list);

    return 0;
}