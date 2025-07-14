#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp;

    if((fp = fopen("p60_no.txt", "r")) == NULL){
        printf("标准输出");
        fputs("打开文件失败！\n", stderr);  //打印到标准错误处理流
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    return 0;
}