#include <stdio.h>

long fact(int num);

long fact(int num){
    if (num > 1){
        return num * fact(num - 1);
    }
    else{
        return 1;
    }
    
}

int main(){
    int num1;

    printf("输入一个正整数：");
    scanf("%d", &num1);
    printf("%d\n", fact(num1));

    return 0;
}
