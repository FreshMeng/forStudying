#include <stdio.h>

struct Date{
    int year;
    int month;
    int day;
};

struct Book{
    char title[120];
    char author[40];
    float price;
    struct Date date;
    char publisher[40];
} book = {
    "带你学C带你飞",
    "小甲鱼",
    48.8,
    {2017, 11, 1},
    "清华大学出版社"
};

int main(void){
    // printf("书名：%s\n", book.title);
    // printf("作者：%s\n", book.author);
    // printf("售价：%.2f\n", book.price);
    // printf("出版日期：%4d-%02d-%02d\n", book.date.year, book.date.month, book.date.day);
    // printf("出版社：%s\n", book.publisher);

    // 结构体指针
    struct Book *pt;
    pt = &book;
    // printf("书名：%s\n", (*pt).title);
    // printf("作者：%s\n", (*pt).author);
    // printf("售价：%.2f\n", (*pt).price);
    // printf("出版日期：%4d-%02d-%02d\n", (*pt).date.year, (*pt).date.month, (*pt).date.day);
    // printf("出版社：%s\n", (*pt).publisher);
    printf("书名：%s\n", pt->title);
    printf("作者：%s\n", pt->author);
    printf("售价：%.2f\n", pt->price);
    printf("出版日期：%4d-%02d-%02d\n", pt->date.year, pt->date.month, pt->date.day);
    printf("出版社：%s\n", pt->publisher);

    return 0;
}

