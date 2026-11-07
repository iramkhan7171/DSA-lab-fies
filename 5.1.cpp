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
    int n, value;

    cout<<"Enter number of values";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter value";
        cin>>value;

        Node* newNode=new Node;
        newNode->data=value;
        newNode->next=head;
        head=newNode;
    }

    cout<<"Enter value to insert at beginning";
    cin>>value;

    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=head;
    head=newNode;

    cout<<"Linked List";

    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}