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
void insertAfter(int key, int value){
    Node* temp=head;
    while(temp!=NULL&&temp->data!=key){
        temp=temp->next;
    }
    if(temp==NULL){
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
void deleteFirst(){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    head=head->next;

    if(head!=NULL){
        head->prev=NULL;
    }
    delete temp;
}
void deleteByValue(int value){
    Node* temp=head;

    while(temp!=NULL&&temp->data!=value){
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    if(temp->prev!=NULL){
        temp->prev->next=temp->next;
    }else{
        head=temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}
void deleteLast(){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->prev!=NULL){
        temp->prev->next=NULL;
    } else {
        head=NULL;
    }
    delete temp;
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
    insertAtEnd(101);
    insertAtEnd(102);
    insertAtEnd(103);
    insertAtEnd(104);
    insertAtEnd(105);
    insertAtStart(100);
    insertAfter(103, 1035);
    insertAtEnd(106);
    deleteFirst();
    deleteByValue(104);
    deleteLast();
    cout<<"Final Doubly Linked List"<<endl;
    display();

    return 0;
}
