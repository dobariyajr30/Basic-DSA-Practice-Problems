#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
    struct node *Next;
    int data;
}*Head;

void create()
{
    struct node *temp,*q;
    int value;

    cout<<"\nEnter Value-->";
    cin>>value;

    temp=(struct node*)malloc(sizeof(temp));
    temp->data=value;
    temp->Next=NULL;

    if(Head==NULL)
    {
        Head=temp;
    }
    else
    {
        q=Head;

        while(q->Next!=NULL)
        {
            q=q->Next;
        }
        q->Next=temp;
    }
}

void print()
{
    struct node *temp,*q;

    if(Head==NULL)
    {
        cout<<"Link List is empty\n";
    }
    else
    {
        q=Head;

        while(q!=NULL)
        {
            cout<<"-->"<<q->data;
            q=q->Next;
        }
    }
}

int cnt()
{
   struct node *q;
   int c=0;

   if(Head==NULL)
   {
       return 0;
   }
   else
    {
        q=Head;

        while(q!=NULL)
        {
            q=q->Next;
            c++;
        }

        return c;
   }
}

void in_first()
{
    struct node *temp,*q;
    int value;

    cout<<"\nInsert any value-->";
    cin>>value;

    temp=(struct node*)malloc(sizeof(temp));
    temp->data=value;
    temp->Next=Head;
    Head=temp;
}
void in_last()
{
    struct node *temp,*q;
    int value;

    cout<<"Enter Value-->";
    cin>>value;

    if(Head==NULL)
    {
        cout<<"There is no item in Link List";
    }
    else
    {
        q=Head;

        temp=(struct node*)malloc(sizeof(temp));
        temp->data=value;
        temp->Next=NULL;

        while(q->Next!=NULL)
        {
            q=q->Next;
        }
        q->Next=temp;
    }
}

void in_at()
{
    struct node *temp,*q;
    int value,i,pos;

    cout<<"At which Position you want add-->";
    cin>>pos;

    if(pos<cnt())
    {

    }
}


main()
{
    int opt;

    do
    {
        cout<<"\nPress 1 for Printing Data\n";
        cout<<"Press 2 for New Node Creation\n";
        cout<<"Press 3 for Count the Number of Data\n";
        cout<<"Press 4 for Insert Node at starting\n";
        cout<<"Press 5 for Insert Node at Last\n";
        cin>>opt;

        if(opt==1)
        {
            print();
        }
        else if(opt==2)
        {
            create();
        }
        else if(opt==3)
        {
            cout<<"The Number of Data is "<<cnt()<<" \n";
        }
        else if(opt==4)
        {
            in_first();
        }
        else if(opt==5)
        {
            in_last();
        }
    }
    while(opt<=10);
}
