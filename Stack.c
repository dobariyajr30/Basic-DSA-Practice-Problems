#include<stdio.h>
#define N 5

int stack[N];
int top=-1;

void push()
{
    if(top<N)
    {
        int no;

        printf("Enter Digit to push-->");
        scanf("%d",&no);

        top++;
        stack[top]=no;
        printf("\nAfter insert top at %d",top);
    }
    else
    {
        printf("Stack Overflow");
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("We are deleting %d element of Stack\n",stack[top]);
        top--;
        printf("\nAfter Delete top at %d",top);
    }
}

void printstack()
{
    int i;
    printf("\ntop at %d\n",top);

    for(i=top; i>=0; i--)
    {
        printf("[%d]\n",stack[i]);
    }
}

main()
{
    int opt;
    do{
    printf("\n\n~Stack~\n");
    printf("1 for Push\n");
    printf("2 for Pop\n");
    printf("3 for Show\n");
    printf("4 for Exit\n");
    scanf("%d",&opt);

    if(opt==1)
    {
        push();
    }
    else if(opt==2)
    {
        pop();
    }
    else if(opt==3)
    {
        printstack();
    }
    else if(opt==4)
    {
        printf("\nBye");
    }
    else
    {
        printf("Wrong option");
    }
    }while(opt!=5);
}
