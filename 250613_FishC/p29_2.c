#include <stdio.h>

void get_array(int a[10]);

void get_array(int a[10]){
    int i;
    a[5] = 520;
    for (i = 0; i<10; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
}

int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    get_array(a);
    printf("在main中：\n");
    int i;
    for (i = 0; i<10; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    
    return 0;
}