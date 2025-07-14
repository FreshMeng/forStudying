#include <stdio.h>

int main(){
    // int a;
    // int *p = &a;
    // printf("请输入一个整数：");
    // scanf("%d", &a);
    // printf("a = %d\n", a);
    // printf("请重新输入一个整数：");
    // scanf("%d", p);
    // printf("a = %d\n", a);

    // char str1[128];  //数组名是数组第一个元素的地址
    // printf("请输入鱼C的域名：");
    // scanf("%s", str1);
    // printf("鱼C工作室的域名是：%s\n", str1);
    // printf("str1的地址是：%p\n", str1);
    // printf("str1的地址是：%p\n", &str1[0]);

    char a[] = "FishC";
    int b[5] = {1, 2, 3, 4, 5};
    float c[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    char *p = a;
    printf("*P = %c, *(p+1) = %c, *(p+2) = %c\n", *p, *(p+1), *(p+2));
    

    return 0;
}