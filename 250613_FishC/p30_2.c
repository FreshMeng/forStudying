#include <stdio.h>

int square(int num);

int square(int num){
    return num * num;
}


int main(){
    int num;
    int (*fp)(int);  //指向函数的指针

    printf("请输入一个整数：");
    scanf("%d", &num);

    fp = square;

    printf("%d * %d = %d\n",num, num, (*fp)(num));
    printf("%d * %d = %d\n",num, num, fp(num));  //也可以这样写

    return 0;
}