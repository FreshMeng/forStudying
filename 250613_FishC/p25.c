#include <stdio.h>
//#define NULL ((void *)0)  //空指针，指向地址0

int main(){
    int num = 1024;
    int *pi = &num;
    char *ps = "FishC";
    void *pv;  //void指针，可以指向任何类型

    pv = pi;
    printf("pi:%p, pv:%p\n", pi, pv);
    printf("*pv:%d\n", *(int *)pv);

    pv = ps;
    printf("ps:%p, pv:%p\n", ps, pv);
    printf("*pv:%s\n", (char *)pv);
    printf("*pv:%c\n", *(char *)pv);

    printf("ps:%p\n", ps);
    printf("ps:%s\n", ps);
    printf("ps+1:%p\n", ps+1);
    printf("ps+1:%s\n", ps+1);
    printf("*ps:%p\n", *ps);
    printf("*ps:%c\n", *ps);
    printf("*ps+1:%p\n", *ps+1);
    printf("*ps+1:%c\n", *ps+1);

    return 0;
}