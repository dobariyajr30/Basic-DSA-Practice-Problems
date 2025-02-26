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

int cnt()
{
    struct node *q;
    int cnt=0;

    if(Head==NULL)
    {
       return 0;
    }
    else
    {
        q=Head;

        while(q!=NULL)
        {
            cnt++;
            q=q->Next;
        }

       return cnt;

    }
}

void In_at()
{
    struct node *temp,*q;
    int i,pos,value;

    cout<<"Enter Position where you have to Enter New Data";
    cin>>pos;

    if(pos<cnt())
    {
        q=Head;
        cout<<"Enter Value=>";
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
        cout<<"Not Possible !!!";
    }

    for(i=0; i<pos; i++)
    {

    }
}

void del_at()
{
    struct node *temp,*q;
    int pos,i;

    cout<<"Enter Position where you have to delete-->";
    cin>>pos;

    if(pos<cnt()&& pos>0)
    {
        q=Head;

        for(i=1; i<pos-1; i++)
        {
            q=q->Next;
        }
        temp=q->Next;

        cout<<"remove Data-->"<<(temp->data);
        q->Next=temp->Next;
        free(temp);
    }
    else{
        cout<<"Not possible";
    }
}

main()
{
    int opt;
    do{
        cout<<"\n\n~Link List~\n";
        cout<<"1 for Insertion\n";
        cout<<"2 for Show\n";
        cout<<"3 for Insert At First Position\n";
        cout<<"4 for Insert At Last Position\n";
        cout<<"5 for Insert At Rendome Position\n";
        cout<<"6 for Delete At First Position\n";
        cout<<"7 for Delete At Last Position\n";
        cout<<"8 for Delete At Rendome Position\n";
        cout<<"9 for counting the Data in Link List\n";
        cout<<"10 for Exit\n";
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
            In_at();
        }
        else if(opt==6)
        {
            del_first();
        }
        else if(opt==7)
        {
            del_last();
        }
        else if(opt==8)
        {
            del_at();
        }
        else if(opt==9)
        {
           cout<<"Total nodes in the linked list: "<<cnt()<<endl;
        }
        else if(opt==10)
        {
            cout<<"Exit !!!";
        }
    }while(opt<=10);

}

