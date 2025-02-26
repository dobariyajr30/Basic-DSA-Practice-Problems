#include<iostream>
using namespace std;

struct node
{
    struct node *Next,*pre;
    int data;
}*Head;

void create()
{
    struct node *temp,*q;
    int value;

    cout<<"Enter Value-->";
    cin>>value;

    temp=(struct node*)malloc(sizeof(temp));
    temp->data=value;
    temp->Next=NULL;

    if(Head==NULL)
    {
        temp->pre=NULL;
        Head=temp;
    }
    else
    {
        q=Head;

        while(q->Next!=NULL)
        {
            q=q->Next;
        }
        temp->pre=q;
        q->Next=temp;
    }
}

void print()
{
    struct node *q;

    if(Head==NULL)
    {
        cout<<"Link List is Empty\n ";
    }
    else
    {
        q=Head;

        while(q!=NULL)
        {
            cout<<"\t-->"<<q->data;
            q=q->Next;
        }
    }
}

main()
{
    int opt;
    do
    {
        cout<<"\n1 for Printing\n";
        cout<<"2 for Creating New Node\n";
        cin>>opt;

        if(opt==1)
        {
            print();
        }
        else if(opt==2)
        {
            create();
        }

    }while(opt<=10);
}
