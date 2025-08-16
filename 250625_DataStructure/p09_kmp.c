#include <stdio.h>
#include <stdlib.h>

typedef struct String{
    char* data;
    int len;
}String;

String* initString(){
    String* s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}

void stringAssign(String* s, char* data){
    if(s->data){
        free(s->data);
    }
    int len = 0;
    char* temp = data;
    while(*temp){
        len++;
        temp++;
    }
    if(len == 0){
        s->data = NULL;
        s->len = 0;
    }
    else{
        temp = data;  //重置temp指针
        s->len = len;
        s->data = (char*)malloc(sizeof(char) * (len+1));
        for (int i=0; i<len; i++,temp++){
            s->data[i] = *temp;
        }
    }
}

void printString(String* s){
    for(int i=0; i<s->len; i++){
        printf(i==0 ? "%c" : "->%c", s->data[i]);
    }
    printf("\n");
}

int* getNext(String* s){  //公共前后缀next数组
    int* next = (int*)malloc(sizeof(int) * (s->len));
    int i = 0;  //next索引
    int j = -1;  //next值
    next[0] = -1;
    while(i<(s->len-1)){
        if((j==-1) || (s->data[i]==s->data[j])){
            i++;
            j++;
            next[i] = j;
        }
        else{
            j = next[j];
        }
    }
    return next;
}

void printNext(int* next, int len){
    for(int i=0; i<len; i++){
        printf(i==0 ? "%d" : "->%d", next[i]);
    }
    printf("\n");
}

int kmpMatch(String* master, String* sub, int* next){
    int i = 0;  //master指针
    int j = 0;  //sub指针
    while(i<master->len && j<sub->len){
        if(j==-1 || master->data[i]==sub->data[j]){
            i++;
            j++;
        }
        else{
            j = next[j];  //不改变master指针，只对sub指针做修改
        }
    }
    if (j==sub->len){
        printf("kmp match success\n");
        return i-j;
    }
    else{
        printf("kmp match fail\n");
        return -1;
    }
}


int main(){
    String* s = initString();
    stringAssign(s, "abaccababd");
    String* s1 = initString();
    stringAssign(s1, "abab");
    printString(s);
    printString(s1);
    int* next = getNext(s);
    printNext(next, s->len);
    int index = kmpMatch(s, s1, next);
    printf("%d", index);

    return 0;
}