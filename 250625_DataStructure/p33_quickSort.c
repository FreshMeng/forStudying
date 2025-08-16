#include <stdio.h>

void printArray(int array[], int length){
    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

//自己写的
void quickSort(int array[], int start, int end, int length){
    if(start >= end){
        return;
    }
    int aim = start;
    int start1 = start;
    int end1 = end;
    while(start != end){
        if(aim==start){  //从后向前扫
            if(array[end] >= array[aim]){  //大的放在左边
                end--;
            }else{  //小的放到右边，交换
                int temp = array[aim];
                array[aim] = array[end];
                array[end] = temp;
                aim = end;
            }
        }else if(aim==end){  //从前向后扫
            if(array[start] <= array[aim]){  //小的放在右边
                start++;
            }else{  //大的放到左边，交换
                int temp = array[aim];
                array[aim] = array[start];
                array[start] = temp;
                aim = start;
            }
        }
    }
    int rLen = aim - start1;
    int lLen = end1 - aim;
    quickSort(array, aim-1-rLen+1, aim-1, rLen);
    quickSort(array, aim+1, aim+1+lLen-1, lLen);
}


//老师写的
int partition(int array[], int i, int j){  //返回分左右的索引
    int x = array[i];  //拿出目标值，i成为空值位
    while(i < j){
        while(i < j && array[j] >= x){
            j--;
        }
        if(i < j){  //空值位转到j，i位存原本的j位值
            array[i] = array[j];
            i++;
        }
        while(i < j && array[i] < x){
            i++;
        }
        if(i < j){  //空值位转到i，j位存原本的j位值
            array[j] = array[i];
            j--;
        }
    }
    array[i] = x;  //给空值位赋目标值，此时ij相等
    return i;
}

void quickSort2(int array[], int i, int j){
    if(i < j){
        int index = partition(array, i, j);
        quickSort2(array, i, index-1);
        quickSort2(array, index+1, j);
    }
}

int main(){
    // int array[10] = {49,38,65,97,76,13,27,49,55,4};
    // quickSort(array, 0, 9, 10);
    // printArray(array, 10);
    int array2[8] = {27, 38, 13, 49, 76, 97, 65, 49};
    quickSort(array2, 0, 7, 8);
    printArray(array2, 8);
    int array3[8] = {27, 38, 13, 49, 76, 97, 65, 49};
    quickSort2(array3, 0, 7);
    printArray(array3, 8);
    
    return 0;
}