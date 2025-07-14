#include <stdio.h>

int main(){
    //字符串的字符数
    // char str1[] = "I love FishC.com!";
    // char *target1 = str1;
    // int count = 0;
    // while(*target1++ != '\0'){
    //     count++;
    // }
    // printf("总共有%d个字符！\n", count);

    //指针数组
    // char *p1[5] = {
    //     "sentence1",
    //     "sentence2",
    //     "sentence3",
    //     "sentence4",
    //     "sentence5"
    // };
    // int i;
    // for(i = 0; i<5; i++){
    //     printf("%s\n", p1[i]);
    //     printf("%p\n", p1[i]);
    //     printf("%c\n", *p1[i]);
    // }

    //数组指针
    int temp[5] = {1,2,3,4,5};
    int (*p2)[5] = &temp;
    int i;
    for(i=0; i<5; i++){
        printf("%d\n", *(*p2 + i));
    }


    return 0;

}