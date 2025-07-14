#include <stdio.h>

int sum(int n);
int max(int a, int b);

int sum(int n){
    if(n == 1){
        return 1;
    }
    else if(n <= 0){
        return 0;
    }
    else{
        return n+sum(n-1);
    }
}

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    } 
}

int main(){
    // int n;
    // scanf("%d", &n);
    // printf("%d\n",sum(n));

    int a,b;
    scanf("%d\n%d", &a, &b);
    printf("%d\n",max(a, b));

    return 0;
}