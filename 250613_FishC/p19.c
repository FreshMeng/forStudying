#include <stdio.h>
#include <string.h>


int main()
{
    //字符串长度
    // char str[] = "I love FishC.com";
    // printf("sizeof str = %d\n",sizeof(str));
    // printf("strlen str = %u\n",strlen(str));

    //拷贝字符串
    // char str1[] = "Original String";
    // char str2[] = "New String";
    // char str3[100];
    // strcpy(str1, str2);  //str1要能容纳str2 strcpy(str2, str1);
    // strcpy(str3, "Copy Successful");
    // printf("str1: %s\n", str1);
    // printf("str2: %s\n", str2);
    // printf("str3: %s\n",  str3);

    //规定长度的拷贝字符串
    // char str1[] = "To be or not to be";
    // char str2[40];
    // strncpy(str2, str1, 5);
    // str2[5] = '\0'; //函数不会追加结束符，要手动追加
    // printf("str2: %s\n", str2);

    //字符串拼接
    // char str1[] = "I love";
    // char str2[] = "FishC.com!";
    // strcat(str1, " ");
    // strcat(str1, str2);
    // printf("str1: %s\n", str1);

    //比较字符串
    char str1[] = "FishC.com!";
    char str2[] = "FishC.com!";
    if (!strcmp(str1, str2)) //一致返回0
    {
        printf("两个字符串完全一致！\n");
    }
    else
    {
        printf("两个字符串存在差异！\n");
    }
    return 0;
}
