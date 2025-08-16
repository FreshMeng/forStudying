#include <stdio.h>

void printArray(int array[], int length){
    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int array[], int length){
    for(int i=0; i<length-1; i++){
        for(int j=0; j<length-i-1;j++){
            int temp = array[j];
            if(array[j] > array[j+1]){
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        // printArray(array, 10);
    }
}

int main(){
    int array[10] = {49,38,65,97,76,13,27,49,55,4};
    bubbleSort(array, 10);
    printArray(array, 10);
    
    return 0;
}