#include <stdio.h>

//根据用户输入的+-号判断用哪个函数
//函数返回 函数指针
int add(int num1, int num2);
int sub(int num1, int num2);
int calc(int (*)(int, int), int num1, int num2);
int (*select(char))(int, int);
// *select(char)：char类型参数，返回一个指针
// (*)(int, int)：指向两个int参数的函数指针

int add(int num1, int num2){
    return num1 + num2;
}
int sub(int num1, int num2){
    return num1 - num2;
}

int calc(int (*fp)(int, int), int num1, int num2){
    return (*fp)(num1, num2);
}

int (*select(char op))(int, int){
    switch(op){
        case '+': return add;
        case '-': return sub;
    }
}


int main(){
    int num1, num2;
    char op;
    int (*fp)(int, int);

    printf("请输入一个式子（如1+3）：");
    scanf("%d%c%d", &num1, &op, &num2);

    fp = select(op);
    printf("%d %c %d = %d\n",num1, op, num2, calc(fp, num1, num2));



    return 0;
}