#include <stdio.h>

void swap(int *x, int *y);

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x = 3, y = 5;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    return 0;
}