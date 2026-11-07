#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertAtStart(Node*& head, int value)
{
    Node* newNode=new Node;

    newNode->data=value;
    newNode->next=head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value)
{
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

void insertInMiddle(Node* head, int searchValue, int newValue)
{
    Node* temp=head;

    while(temp!=NULL&&temp->data!=searchValue)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        cout<<"Value not found\n";
    }
    else
    {
        Node* newNode=new Node;

        newNode->data=newValue;
        newNode->next=temp->next;
        temp->next=newNode;

        cout<<"Value inserted successfully\n";
    }
}

void display(Node* head)
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

int main()
{
    Node* head=NULL;
    int choice, value, searchValue;

    do
    {
        cout<<"\n MENU \n";
        cout<<"1. Insert at Start\n";
        cout<<"2. Insert at End\n";
        cout<<"3. Insert in Middle\n";
        cout<<"4. Display List\n";
        cout<<"5. Exit\n";

        cout<<"Enter choice";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"Enter value";
            cin>>value;
            insertAtStart(head, value);
            break;

        case 2:
            cout<<"Enter value";
            cin>>value;
            insertAtEnd(head, value);
            break;

        case 3:
            cout<<"Enter existing value";
            cin>>searchValue;

            cout<<"Enter new value";
            cin>>value;

            insertInMiddle(head, searchValue, value);
            break;

        case 4:
            display(head);
            break;

        case 5:
            cout<<"Program ended";
            break;

        default:
            cout<<"Invalid choice\n";
        }

    } while(choice != 5);

    return 0;
}