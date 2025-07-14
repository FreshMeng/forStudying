#include <stdio.h>
//汉诺塔
void hanoi(int n, char x, char y, char z);

void hanoi(int n, char x, char y, char z){
    if (n == 1){
        printf("%c --> %c\n", x, z);
    }
    else{
        hanoi(n-1, x, z, y);
        hanoi(1, x, y, z);
        hanoi(n-1, y, x, z);
    }
}

int main(){
    hanoi(3, 'x', 'y', 'z');
    return 0;
}