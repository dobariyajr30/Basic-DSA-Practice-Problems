#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
    int data;
    struct node *Next;

}*Head;

void creat()
{
    struct node *temp,*q;
    int value;

    cout<<"\n Enter Value:-";
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
    struct node *q;

    if(Head==NULL)
    {
        cout<<"Link List is Empty\n";
    }
    else
    {
        q=Head;

        cout<<"\nItems Are->\n";

        while(q!=NULL)
        {
            cout<<"\t-->"<<q->data;
            q=q->Next;
        }
    }
}

void In_first()
{
    struct node *temp;
    int value;

    cout<<"Enter value-->";
    cin>>value;

    temp=(struct node*)malloc(sizeof(temp));
    temp->data=value;
    temp->Next=Head;
    Head=temp;

}

void In_last()
{
    struct node *temp,*q;
    int value;

    cout<<"Enter value-->";
    cin>>value;

    if(Head==NULL)
    {
        cout<<"There is no item\n";
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

void del_first()
{
    struct node *temp;

    if(Head==NULL)
    {
        cout<<"Link List is already empty\n";
    }
    else
    {
        temp=Head;
        Head=Head->Next;
        free(temp);
    }
}

void del_last()
{
    struct node *temp,*q;

    if(Head==NULL)
    {
        cout<<"Link List is already Empty\n";
    }
    else
    {   q=Head;

        while(q->Next->Next!=NULL)
        {
            q=q->Next;
        }
        temp=q->Next;
        cout<<"\n Last Item remove ="<<temp->data;
        q->Next=NULL;
        free(temp);
    }
}

main()
{
    int opt;
    do{
        cout<<"\n~Link List~\n";
        cout<<"1 for Insertion\n";
        cout<<"2 for Show\n";
        cout<<"3 for Insert At First Position\n";
        cout<<"4 for Insert At Last Position\n";
        cout<<"5 for Delete At First Position\n";
        cout<<"6 for Delete At Last Position\n";
        cout<<"7 for Exit\n";
        cin>>opt;

        if(opt==1)
        {
            creat();
        }
        else if(opt==2)
        {
            print();
        }
        else if(opt==3)
        {
            In_first();
        }
        else if(opt==4)
        {
            In_last();
        }
        else if(opt==5)
        {
            del_first();
        }
        else if(opt==6)
        {
            del_last();
        }
        else if(opt==7)
        {
            cout<<"Bye";
        }
    }while(opt<=7);

}
