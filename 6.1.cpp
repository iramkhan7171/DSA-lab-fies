#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;
void deleteAtStart(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
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
    head=new Node{10, NULL};
    head->next=new Node{20, NULL};
    head->next->next=new Node{30, NULL};
    head->next->next->next=new Node{40, NULL};
    head->next->next->next->next=new Node{50, NULL};
    deleteAtStart();
    display();
    deleteAtStart();
    display();
    return 0;
}