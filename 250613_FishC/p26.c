#include <stdio.h>

int main(){
    //指向指针的指针
    // int num = 520;
    // int *p = &num;
    // int **pp = &p;  //解引用两次后的类型是int
    // printf("num = %d\n", num);
    // printf("*p = %d\n", *p);
    // printf("**pp = %d\n", **pp);
    // printf("&p = %p, pp = %p\n", &p, pp);
    // printf("&num = %p, p = %p, *pp = %p\n", &num, p, *pp);

    //用指向指针的指针 指向 指针数组
    // char *cBooks[] = {
    //     "《C程序设计语言》",
    //     "《C专家编程》",
    //     "《C和指针》",
    //     "《C陷阱与缺陷》",
    //     "《C Primer Plus》",
    //     "《带你学C带你飞》"
    // };
    // char **byFishC;
    // char **jiayuLoves[4];
    // int i; 
    // byFishC = &cBooks[5];
    // jiayuLoves[0] = &cBooks[0];
    // jiayuLoves[1] = &cBooks[1];
    // jiayuLoves[2] = &cBooks[2];
    // jiayuLoves[3] = &cBooks[3];
    // printf("FishC出版的图书有：%s\n", *byFishC);
    // printf("小甲鱼喜欢的图书有：\n");
    // for(i = 0; i < 4; i++){
    //     printf("%s\n", *jiayuLoves[i]);
    // }
    
    //指针使用数组
    // int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int *p = array;
    // int i;
    // for(i = 0; i < 10; i++){
    //     printf("%d\n", *(p + i));
    // } 

    //数组指针和二维数组
    int array[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int (*p)[4] = array;
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j<4; j++){
            printf("%2d ", *(*(p + i)+j));
        }
        printf("\n");
    }

    return 0;
}