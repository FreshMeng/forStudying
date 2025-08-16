//插入排序
#include <stdio.h>

void printArray(int array[], int length){
    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertSort(int array[], int length){
    for(int i=1; i<length; i++){  //从第二个元素开始比较从0-前一个元素之间有无合适位置插入
        for(int j=0; j<i; j++){
            if(array[i] < array[j]){  //插到前面
                int temp = array[i];
                for(int k=i-1; k>=j; k--){  //数据后移
                    array[k+1] = array[k];
                }
                array[j] = temp;
            }
        }
        //printArray(array, 6);
    }
}



int main(){
    int array[6] = {4,3,5,1,9,6};
    printArray(array, 6);
    insertSort(array, 6);
    printArray(array, 6);
    return 0;
}