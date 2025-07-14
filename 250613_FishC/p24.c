# include <stdio.h>

int main(){
    //二维数组
    // int array[4][5] = {0};
    // int i, j, k = 0;
    // for(i = 0; i < 4; i++){
    //     for(j=0; j < 5; j++){
    //         array[i][j] = k++;
    //     }
    // }
    // printf("sizeof int: %d\n", sizeof(int));
    // printf("array: %p\n", array);
    // printf("array + 1: %p\n", array + 1);
    // printf("*(array+1): %p\n", *(array+1));
    // printf("array[1]: %p\n", array[1]);
    // printf("&array[1][0]: %p\n", &array[1][0]);
    // printf("**(array+1): %d\n", **(array+1));
    // printf("*(*(array+1)+3): %d\n", *(*(array+1)+3));
    // printf("array[1][3]: %d\n", array[1][3]);

    //二维数组和数组指针,array是指向3个元素的数组指针
    int array[2][3] = {{0, 1, 2}, {3, 4, 5}};
    int (*p)[3] = array;
    printf("**(p+1): %d\n", **(p+1));
    printf("**(array+1): %d\n", **(array+1));
    printf("array[1][0]: %d\n", array[1][0]);
    printf("*(*(p+1)+2): %d\n", *(*(p+1)+2));
    printf("*(*(array+1)+2): %d\n", *(*(array+1)+2));
    printf("array[1][2]: %d\n", array[1][2]);

    return 0;
}