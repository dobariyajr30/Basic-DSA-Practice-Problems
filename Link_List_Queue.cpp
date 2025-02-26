#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front=NULL;
Node* rear=NULL;

void insertQ()
{
    int value;
    cout<<"Enter Number->";
    cin>>value;

    struct Node *temp;

    temp=(struct Node*)malloc(sizeof(temp));
    temp->data=value;
    temp->next=NULL;

    if (rear==NULL)
    {
        front=rear=temp;
        cout<<"Inserted at Front and Rear: "<<value<<endl;
    }

    rear->next=temp;
    rear=temp;
    cout<<"Inserted: "<<value<<endl;
}

void deleteQ()
{
    if (front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }

    struct Node *temp;
    temp=front;

    cout<<"Deleting: "<<front->data<<endl;
    front=front->next;

    if (front==NULL)
    {
        rear=NULL;
    }

    delete temp;
}

void printQ()
{
    if (front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }

    Node* temp=front;
    cout<<"Queue elements: ";
    while (temp!=NULL)
    {
        cout<<temp->data<<" ==> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    int opt;
    do
    {
        cout<<"\n1 for Insert Value in Queue"<<endl;
        cout<<"2 for Delete Value in Queue"<<endl;
        cout<<"3 for Print Value in Queue"<<endl;
        cout<<"4 for Exit"<<endl;
        cin >> opt;

        if (opt==1)
        {
            insertQ();
        }
        else if (opt==2)
        {
            deleteQ();
        }
        else if (opt==3)
        {
            printQ();
        }
        else if (opt==4)
        {
            cout<<"Bye"<<endl;
        }
    } while (opt!= 4);

    return 0;
}

