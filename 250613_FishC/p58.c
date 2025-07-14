#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    FILE *fp;
    struct tm *p;
    time_t t;

    time(&t);
    p = localtime(&t);

    if ((fp = fopen("p58_date.txt", "w")) == NULL){
        printf("打开文件失败！\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%d-%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    fclose(fp);
    
    int year, month, day;
    if ((fp = fopen("p58_date.txt", "r")) == NULL){
        printf("打开文件失败!\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d-%d-%d", &year, &month, &day);
    printf("%d-%d-%d\n", year, month, day);

    fclose(fp);

    return 0;
}