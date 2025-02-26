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

void In_first()
{
    struct node *temp;
    int value;

    cout<<"Enter Value->";
    cin>>value;

    temp=(struct node*)malloc(sizeof(temp));
    temp->pre=NULL;
    temp->data=value;

    if(Head==NULL)
    {
        cout<<"Link List is Empty";
    }
    else
    {
        temp->Next=Head;
        Head->pre=temp;
        Head=temp;

        cout<<"Inserted Successfully \n";
    }
}

void In_last()
{
    struct node *temp,*q;
    int value;

    cout<<"Enter Value-->";
    cin>>value;

    temp=(struct node*)malloc(sizeof(temp));
    temp->Next=NULL;
    temp->data=value;

    if(Head==NULL)
    {
        cout<<"Link List is Empty\n";
    }
    else
    {
        q=Head;

        while(q->Next!=NULL)
        {
            q=q->Next;
        }
        q->Next=temp;
        temp->pre=q;

        cout<<"Inserted Successfully \n";
    }
}

void In_at()
{
    struct node *temp,*q;
    int value,pos;

    cout<<"Enter Position-->";
    cin>>pos;

    if(Head==NULL)
    {
        cout<<"Link List Empty\n";
    }
    else
    {
        if(pos<cnt())
        {
            int value,i;

            cout<<"Enter Value-->";
            cin>>value;

            temp=(struct node*)malloc(sizeof(temp));
            temp->data=value;
            q=Head;

            for(i=1; i<pos; i++)
            {
                q=q->Next;
            }
            q->Next->pre=temp;
            temp->Next=q->Next;
            temp->pre=q;
            q->Next=temp;

            cout<<"Insertion Done Successfully";
        }
        else
        {
            cout<<"Not Possible\n";
        }
    }
}

void del_first()
{
    struct node *temp;

    if(Head==NULL)
    {
        cout<<"Link List is Empty\n";
    }
    else
    {
        temp=Head;
        Head=Head->Next;
        Head->pre=NULL;

        free(temp);
        cout<<"Head is Updated \n";
    }
}

void del_last()
{
    struct node *temp,*q;

    if(Head==NULL)
    {
        cout<<"Link List is Epmty";
    }
    else
    {
        q=Head;

        if(q->Next==NULL)
        {
            q=q->Next;
        }
        temp=q->Next;
        q->Next=NULL;

        free(temp);
        cout<<"Last Deleted !!!\n";
    }
}

void del_at()
{
    struct node *temp,*q;

    if(Head==NULL)
    {
        cout<<"Not Possible\n";
    }
    else
    {
        int pos;

        cout<<"Enter Position-->";
        cin>>pos;

        if(pos<cnt())
        {
            int i;

            q=Head;

            for(i=1; i<pos; i++)
            {
                q=q->Next;
            }
            temp=q->Next;
            q->Next=temp->Next;
            q->Next->pre=q;

            free(temp);
        }
        else
        {
            cout<<"Not Possible\n";
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
        cout<<"3 for Count the Number of Node Present\n";
        cout<<"4 for Inserting Node At First Position\n";
        cout<<"5 for Inserting Node At Last Position\n";
        cout<<"6 for Inserting Node At Any Position\n";
        cout<<"7 for Delete Node At First Position\n";
        cout<<"8 for Delete Node At Last Position\n";
        cout<<"9 for Delete Node At Any Position\n";
        cout<<"10 for Exit\n";
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
            cout<<cnt()<<" Node in Link List\n";
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
            cout<<"Byee \n";
        }


    }while(opt<=10);
}
