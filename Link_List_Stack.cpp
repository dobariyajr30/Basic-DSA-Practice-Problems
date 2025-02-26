#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* top=NULL;

void push()
{
    int value;
    cout<<"Enter Digit to push-->";
    cin>>value;

    struct node *temp;
    temp=(struct node*)malloc(sizeof(temp));
    temp->data=value;
    temp->next=top;
    top=temp;

    cout<<"\nAfter insert, top at "<<top->data<<endl;
}

void pop()
{
    if (top==NULL)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        cout<<"We are deleting "<<top->data<<" element of Stack\n";
        node*temp=top;
        top=top->next;
        delete temp;
    }
}

void printstack()
{
    if (top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }

    struct node *temp;
    temp=(struct node*)malloc(sizeof(temp));

    temp=top;
    cout<<"\nStack elements:\n";

    while (temp!=NULL)
    {
        cout<<"[" << temp->data<<"]\n";
        temp=temp->next;
    }
}

int main()
 {
    int opt;
    do {
        cout<<"\n\n~Stack~\n";
        cout<<"1 for Push\n";
        cout<<"2 for Pop\n";
        cout<<"3 for Show\n";
        cout<<"4 for Exit\n";
        cin>>opt;

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
            cout << "\nBye";
        }
    } while (opt!=4);
}

