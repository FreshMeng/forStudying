#include <stdio.h>
#include <stdlib.h>

//链表 尾插法
struct Book{
    char title[128];
    char author[40];
    struct Book *next; 
};

void getInput(struct Book *book){
    printf("请输入书名：");
    scanf("%s", book->title);
    printf("请输入作者：");
    scanf("%s", book->author);
}

void addBook(struct Book **library){
    struct Book *book;
    static struct Book *tail;

    book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL){
        printf("内存分配失败\n");
        exit(1);
    }

    getInput(book);

    if (*library != NULL){
        // temp = *library;
        // //定位单链表尾部
        // while (temp->next != NULL){
        //     temp = temp->next;
        // }
        // //插入数据
        // temp->next = book;
        // book->next = NULL;
        tail->next = book;
        book->next = NULL;
    }
    else{
        *library = book;
        book->next = NULL;
    }
    tail = book;
}

void printLibrary(struct Book *library){
    struct Book *book;
    int count = 1;

    book = library;
    while(book != NULL){
        printf("Book%d: ", count);
        printf("书名：%s; ", book->title);
        printf("作者：%s", book->author);
        putchar('\n');
        book = book->next;
        count++;
    }
}

void releaseLibrary(struct Book *library){
    struct Book *nowL;
    while(library != NULL){
        nowL = library;
        library = library->next;
        free(nowL);
    }
}

int main(void){
    struct Book *library = NULL;
    int ch;

    while(1){
        printf("是否需要录入书籍信息(Y/N): ");
        do{
            ch = getchar();
        } while(ch != 'Y' && ch != 'N');

        if(ch == 'Y'){
            addBook(&library);
        }
        else{
            break;
        }
    }

    printf("请问是否需要打印图书信息(Y/N): ");
    do{
        ch = getchar();
    } while(ch != 'Y' && ch != 'N');

    if (ch == 'Y'){
        printLibrary(library);
    }

    releaseLibrary(library);

    return 0;
}