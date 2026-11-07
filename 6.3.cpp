#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head=NULL;

void deleteByValue(int value){
    if(head==NULL){
        cout<<"Value not found"<<endl;
        return;
    }
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL&&temp->next->data!=value){
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout<<"Value not found"<<endl;
        return;
    }
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
    head=new Node{25, NULL};
    head->next=new Node{40, NULL};
    head->next->next=new Node{55, NULL};
    head->next->next->next=new Node{70, NULL};
    int value;
    cout<<"Enter value to delete";
    cin>>value;
    deleteByValue(value);
    cout<<"Updated list";
    display();
    return 0;
}