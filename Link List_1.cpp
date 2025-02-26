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

main()
{
    int opt;
    do{
        cout<<"\n~Link List~\n";
        cout<<"1 for Insertion\n";
        cout<<"2 for Show\n";
        cout<<"3 for Exit\n";
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
            cout<<"Byee !!!\n";
        }
    }while(opt<=3);

}
