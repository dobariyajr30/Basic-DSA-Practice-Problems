#include<stdio.h>
#define size 5

int Q[size],front=-1,rear=-1;

void inQ()
{

    if((front==0 && rear==size-1) || (front==rear+1))
    {
        printf("Queue is Full\n");
    }
    else
    {
        if(rear==size-1 && front!=0)
        {
            rear=-1;
        }

        int value;
        printf("Enter value at position %d--->",rear+1);
        scanf("%d",&value);

        Q[++rear]=value;

        printf("\n Insert Successfully !!!\n");

        if(front==-1)
        {
            front=0;
        }
    }
}

void delQ()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is already empty !!!\n");
    }
    else
    {
        printf("\n Delete Element:-%d\n",Q[front++]);

        if(front==size)
        {
            front=0;
        }
        if(front-1==rear)
        {
            front=rear=-1;
        }
    }
}

void display()
{
    if(front==-1)
    {
        printf("\n Circular Queue is Empty !!!\n");
    }
    else
    {
        int i=front;

        printf("\n Circular Queue Elements are:-\n");

        if(front<=rear)
        {
            while(i<=rear)
            {
                printf("%d\t",Q[i++]);
            }
        }
        else
        {
            while(i<=size-1)
            {
                printf("%d\t",Q[i++]);
            }
            i=0;
            while(i<=rear)
            {
                printf("%d\t",Q[i++]);
            }
        }
    }
}

main()
{
        int opt;
    do{
        printf("\n1 for Insert value\n");
        printf("2 for Delete value\n");
        printf("3 for Display value\n");
        printf("4 for Exit value\n");
        scanf("%d",&opt);

        if(opt==1)
        {
            inQ();
        }
        else if(opt==2)
        {
            delQ();
        }
        else if(opt==3)
        {
            display();
        }
        else if(opt==4)
        {
            printf("Bye\n");
        }
        else{
            printf("Wrong Option\n");
        }
    }while(opt!=4);
}
