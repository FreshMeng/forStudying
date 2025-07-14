#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr;
    int num = 123;

    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL){
        printf("分配内存失败");
        exit(1);
    }

    printf("请输入一个整数：");
    scanf("%d", ptr);

    printf("你输入的整数是：%d\n", *ptr);

    //ptr = &num;  //丢失堆地址

    free(ptr);  //释放内存

    printf("你输入的整数是：%d\n", *ptr);
    
    return 0;
}