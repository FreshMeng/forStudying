#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *fp;
    int ch;

    if((fp = fopen("p60_output.txt", "r")) == NULL){
        printf("标准输出\n");
        fputs("打开文件失败！\n", stderr);  //打印到标准错误处理流
        //exit(EXIT_FAILURE);
    }

    while (1){
        ch = fgetc(fp);
        if (feof(fp)){
            break;
        }
        putchar(ch);
    }

    fputc('c', fp);
    if (ferror(fp)){
        fputs("出错了！\n", stderr);
    }

    fclose(fp);

    return 0;
}