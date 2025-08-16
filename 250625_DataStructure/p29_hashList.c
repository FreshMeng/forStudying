#include <stdio.h>
#include <stdlib.h>

#define NUM 5  //哈希长度

typedef struct HashList{
    int num;
    char* data;
} HashList;

HashList* initList(){
    HashList* list = (HashList*)malloc(sizeof(HashList));
    list->num = 0;
    list->data = (char*)malloc(sizeof(char) * NUM);
    for(int i=0; i<NUM; i++){
        list->data[i] = 0;
    }
    return list;
}

int hash(char data){
    return data % NUM;
}

void put(HashList* list, char data){  //线性探测法
    int index = hash(data);
    if(list->data[index] != 0){  //发生冲突时线性探测
        int count = 1;
        while(list->data[index] != 0){  //直到无冲突
            index = hash(hash(data) + count);
            count++;
        }
    }
    list->data[index] = data;
}

int main(){
    HashList* list = initList();
    put(list, 'A');
    put(list, 'F');

    printf("%c\n", list->data[0]);
    printf("%c\n", list->data[1]);

    return 0;
}