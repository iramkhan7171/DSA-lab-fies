#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;
void deleteAtEnd(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
void deleteAtPosition2(){
    if(head==NULL||head->next==NULL){
        cout<<"Position 2 does not exist"<<endl;
        return;
    }
    Node* temp=head;
    Node* toDelete=temp->next;
    temp->next=toDelete->next;
    delete toDelete;
}
void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    head=new Node{133, NULL};
    head->next = new Node{31, NULL};
    head->next->next = new Node{42, NULL};
    head->next->next->next = new Node{51, NULL};
    head->next->next->next->next = new Node{60, NULL};
    deleteAtEnd();
    display();
    deleteAtPosition2();
    display();

    return 0;
}