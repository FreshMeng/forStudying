// 字符串暴力匹配
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
    while (*temp){
        len++;
        temp++;
    }
    if(len == 0){
        s->data = NULL;
        s->len = 0;
    }
    else{
        temp = data;
        s->len = len;
        s->data = (char*)malloc(sizeof(char)*(len+1));
        for(int i=0; i<len; i++,temp++){
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

void forceMatch(String* master, String* sub){
    int i = 0;
    int j = 0;
    while(i<master->len && j<sub->len){
        if(master->data[i] == sub->data[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 1;  //回溯已匹配下标并指向下一个
            j = 0;
        }
    }
    if (j == sub->len){
        printf("force match succes");
    }
    else{
        printf("force match fail");
    }
}

// int main(){
//     String* s = initString();
//     String* s1 = initString();
//     stringAssign(s, "HELLO");
//     stringAssign(s1,"HE");
//     printString(s);
//     printString(s1);
//     forceMatch(s, s1);
    
//     return 0; "miDebuggerPath": "/path/to/gdb",
// }

int main(int argc, char* argv[]){
    String* s = initString();
    String* s1 = initString();
    stringAssign(s, argv[1]);
    stringAssign(s1,argv[2]);
    printString(s);
    printString(s1);
    forceMatch(s, s1);
    
    return 0;
}

//运行方式
//gcc -o p08_forceMatch p08_forceMatch.c
//./p08_forceMatch.exe abc ab


