#include <stdio.h>

int main()
{
    //int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    //int a[3][4] = {{1},{5},{9}};
    //int a[3][4] = {0};
    int a[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    //转秩
    printf("转秩\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

    return 0;
}