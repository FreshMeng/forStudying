#include <stdio.h>

//指针函数，以指针变量作为返回值
char *getWord(char c);

char *getWord(char c){
    switch(c){
        case 'A': return "Apple";
        case 'B': return "Banana";
        case 'C': return "cat";
        case 'D': return "Dog";
        default: return "None";
    }
}

int main(){
    char input;

    printf("请输入一个字母：");
    scanf("%c", &input);
    printf("%s\n", getWord(input));

    return 0;
}