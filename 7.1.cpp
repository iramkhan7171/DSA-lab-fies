#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};
Node* head=NULL;
void insertAtStart(int value){
    Node* newNode=new Node;
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=head;

    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
}
void insertAfter(int key, int value){
    Node* temp=head;
    while(temp!=NULL&&temp->data!=key){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"Value not found!"<<endl;
        return;
    }
    Node* newNode=new Node;
    newNode->data=value;
    newNode->prev=temp;
    newNode->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
}
void insertAtEnd(int value){
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        if(temp->next!=NULL){
            cout<<" <-> ";
        }
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtStart(5);
    insertAfter(20, 25);
    insertAtEnd(60);
    cout << "Final Doubly Linked List:" << endl;
    display();
    return 0;
}
