#include <stdio.h>
#define N 5

int Q[N];
int f=-1;
int r=-1;

void insertQ()
{
    if(r<N)
    {
        if(f==-1)
        {
            f=0;
        }
        r++;

        int no;

        printf("Enter Number->");
        scanf("%d",&no);

        Q[r]=no;

        printf("Inserted on R = %d and F = %d \n",r,f);
    }
    else
    {
        printf("queue is full\n");
    }
}

void deleteQ()
{
    if(f==-1)
    {
        printf("Queue is empty\n");
    }
    else if(f==r)
    {
        printf("Now queue is empty\n");

        f=r=-1;
    }
    else
    {
        printf("Deleting %d element\n",Q[f]);

        f=f+1;


        printf("Now deleted Position on R = %d and F = %d \n",r,f);

    }
}

void printQ()
{
    int i;

    printf("\nAll the values Q\n");
    for(i=f; i<=N; i++)
    {
        printf("%d ==> ",Q[i]);
    }
}

main()
{
     int opt;
     do{
     printf("\n1 for Insert Value in Queue\n");
     printf("2 for Delete Value in Queue\n");
     printf("3 for Print Value in Queue\n");     printf("4 for Exit\n");
     scanf("%d",&opt);

         if(opt==1)
         {
             insertQ();
         }
         else if(opt==2)
         {
             deleteQ();
         }
         else if(opt==3)
         {
             printQ();
         }
         else
         {
             printf("Bye\n");
         }
     }
     while(opt!=4);
}
