#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
    int data;
    struct node *Next;

}*Head;

void create()
{
    struct node *temp,*q;
    int value;

    cout<<"Enter Value-->";
    cin>>value;

    temp=(struct node*)malloc(sizeof(temp));
    temp->data=value;

    if(Head==NULL)
    {
        Head=temp;
        temp->Next=Head;
    }
    else
    {
        q=Head;

        while(q->Next!=Head)
        {
            q=q->Next;
        }
        q->Next=temp;
        temp->Next=Head;
    }
}

void print()
{
    struct node *q;

    if(Head==NULL)
    {
        cout<<"Link List is empty";
    }
    else
    {
        q=Head;

        cout<<"~List of Item Present in Link List~\n";

        cout<<"\t-->"<<q->data;
        q=q->Next;

        while(q!=Head)
        {
         cout<<"\t-->"<<q->data;
         q=q->Next;
        }
        cout<<"\n\n";
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
        q=q->Next;
        c++;

        while(q!=Head)
        {
            q=q->Next;
            c++;
        }
        return c;
    }
}

void In_first()
{
    struct node *temp,*q;

    if(Head==NULL)
    {
        cout<<"Link List is Empty\n";
    }
    else
    {
        int value;

        cout<<"Enter Value-->";
        cin>>value;

        temp=(struct node*)malloc(sizeof(temp));
        temp->data=value;

        q=Head;
        q=q->Next;

        while(q->Next!=Head)
        {
            q=q->Next;
        }
        q->Next=temp;
        temp->Next=Head;
        Head=temp;
    }
}

void In_last()
{
    struct node *temp,*q;

    if(Head==NULL)
    {
        cout<<"Link List is Empty\n";
    }
    else
    {
        int value;

        cout<<"Enter Value-->";
        cin>>value;

        temp=(struct node*)malloc(sizeof(temp));
        temp->data=value;

        q=Head;
        q=q->Next;

        while(q!=Head)
        {
            q=q->Next;
        }
        temp->Next=q->Next;
        q->Next=temp;
        cout<<"Insert At Last Successfully !!!\n";
    }
}

void In_at()
{
    struct node *temp,*q;
    int pos,value,i;

    cout<<"Enter Position you want to enter the data-->";
    cin>>pos;

    if(pos<cnt())
    {
     q=Head;
     cout<<"Enter What you want to Enter-->";
     cin>>value;

     temp=(struct node*)malloc(sizeof(temp));
     temp->data=value;

     for(i=1; i<pos; i++)
     {
         q=q->Next;
     }
     temp->Next=q->Next;
     q->Next=temp;
    }
    else
    {
        cout<<"Not Possible";
    }

}

void del_first()
{
    struct node *temp,*q;

    if(Head==NULL)
    {
        cout<<"Link List is Empty !!!\n";
    }
    else
    {
        q=Head;
        q=q->Next;

        while(q->Next!=Head)
        {
            q=q->Next;
        }
        temp=Head;
        q->Next=Head->Next;
        Head=Head->Next;

        free(temp);
    }
}

void del_last()
{
    struct node *temp,*q;

    if(Head==NULL)
    {
        cout<<"Link List is Empty\n";
    }
    else
    {
        q=Head;
        q=q->Next;

        while(q->Next->Next!=Head)
        {
            q=q->Next;
        }

        temp=q->Next;
        q->Next=q->Next->Next;
        free(temp);

        cout<<"Item Deleted Successfully\n";
    }
}

void del_at()
{
    struct node *temp,*q;
    int pos,i;

    cout<<"Enter Position-->";
    cin>>pos;
    q=Head;

    if(pos<cnt())
    {
        for(i=1; i<pos-1; i++)
        {
            q=q->Next;
        }
        temp=q->Next;
        q->Next=q->Next->Next;
        free(temp);
        cout<<"Delete Successfully\n";
    }
    else
    {
     cout<<"Not Possible";
    }
}

main()
{
    int opt;
    do
    {
        cout<<"\n~Circular Link List~\n";
        cout<<"1 Print the Data\n";
        cout<<"2 for Enter the value in Link List\n";
        cout<<"3 for Count the Data in Link List\n";
        cout<<"4 for Insert Data At First Position\n";
        cout<<"5 for Insert Data At Last Position\n";
        cout<<"6 for Insert Data At Any Particular Position\n";
        cout<<"7 for Delete Data At First Position\n";
        cout<<"8 for Delete Data At Last Position\n";
        cout<<"9 for Delete Data At Any Particular Position\n";
        cout<<"10 For Exit Program\n";
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
            cout<<cnt()<<" Element in Link List";
        }
        else if(opt==4)
        {
            In_first();
        }
        else if(opt==5)
        {
            In_last();
        }
        else if(opt==6)
        {
            In_at();
        }
        else if(opt==7)
        {
            del_first();
        }
        else if(opt==8)
        {
            del_last();
        }
        else if(opt==9)
        {
            del_at();
        }
        else if(opt==10)
        {
            cout<<"Bye Byeeeeee !!!!!\n";
        }
    }while(opt<=10);
}
