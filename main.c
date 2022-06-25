#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int top = -1;
char A[SIZE];

void push(char ch)
{
    if(top > SIZE - 1)return;
    else A[++top] = ch;
}

void pop()
{
    if(top > -1)top--;
    else return;
}

void create_file()
{
    char ch;
    FILE* fp = fopen("myFile.txt", "w");
    if(fp == NULL)
    {
        puts("Cannot open file");
        exit(0);
    }

    while((ch = getchar()) != EOF)putc(ch, fp);
    fclose(fp);
}

void list_comments()
{
    char ch;
    int flag = 0;
    FILE* fp = fopen("myFile.txt", "r");

    if(fp == NULL)
    {
        puts("Cannot open file");
        exit(0);
    }

    /*while((ch = getc(fp)) != EOF)
    {
        if(ch == '/' && flag == 0)
            flag = 1;
        else if(ch == '/' && flag == 1)
            flag = 2;

        if(ch == '*' && flag)

        if(ch == '\n' && flag == 2)flag = 0;

        if(flag == 2 && ch != '/')
            putchar(ch);

        if(flag == 1)push(ch);
    }*/

    while((ch = getc(fp)) != EOF)
    {
        if(ch == '/' && flag == 0)
            flag = 1;

        if((ch == '\n' && flag == 2) || (ch == '/' && A[top] == '*'))
        {
            int i = 0;
            flag = 0;
            while(i <= top)
            {
                if(A[i] != '/' && A[i] != '*')putchar(A[i]);
                i++;
            }
            printf("\n");
            while(top != -1)pop();
        }

        if(flag)push(ch);

        if(top == 1 && flag == 1 && A[1] == '/')flag = 2;

        if(top == 1 && flag == 1 && A[1] == '*')flag = 3;
    }

    fclose(fp);
}

int main()
{
    printf("Create program to analyze:\n");
    create_file();

    printf("\nThe comments in the above program are listed below:\n");
    list_comments();
    return 0;
}
