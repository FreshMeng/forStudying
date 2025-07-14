#include <stdio.h>

int main(){
    //常量
    // const float pi = 3.14;
    // printf("%f\n", pi);
    // //pi = 3.1415;  //修改只读变量，报错

    //指向常量的指针
    // int num = 520;
    // const int cnum = 880;
    // const int *pc = &cnum;  //指向常量的指针
    // printf("cnum: %d, &cnum: %p\n", cnum, &cnum);
    // printf("*pc: %d, pc: %p\n", *pc, pc);
    // //*pc = 1024;  //不能通过指针修改只读变量
    // pc = &num;  //指向常量的指针可以指向变量
    // //*pc = 1024;  //但不能通过它修改变量

    //常量指针
    // int num = 520;
    // const int cnum = 880;
    // int * const p = &num;  //常量指针指向变量
    // *p = 1024;  //可以通过常量指针改变值
    // printf("*p: %d\n", *p);
    // //p = &cnum;  //常量指针自身的指向不能改变
    // const int * const p1 = &cnum;  //常量指针指向常量
    // //*p1 = 1024;  //不可修改值
    // printf("*p1: %d\n", *p1);
    // //p1 = &num;  //也不可修改指向


    return 0;
}