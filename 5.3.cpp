#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* head=NULL;
    int n, value, searchValue, newValue;

    cout<<"Enter number of values";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter value";
        cin>>value;

        Node* newNode=new Node;
        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node* temp=head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=newNode;
        }
    }

    cout<<"Enter existing value";
    cin>>searchValue;

    cout<<"Enter new value";
    cin>>newValue;

    Node* temp=head;

    while(temp!=NULL&&temp->data!=searchValue)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        cout<<"Value not found";
    }
    else
    {
        Node* newNode=new Node;
        newNode->data=newValue;

        newNode->next=temp->next;
        temp->next=newNode;

        cout<<"Value inserted successfully";
    }

    cout<<"\nLinked List";

    temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}