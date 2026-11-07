#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string page;
    Node* next;

    Node(string p){
        page=p;
        next=NULL;
    }
};

class Stack{
    Node* top;

public:
    Stack(){
        top=NULL;
    }

    void push(string page){
        Node* newNode=new Node(page);
        newNode->next=top;
        top=newNode;

        cout<<"Page visited"<<page<<endl;
    }

    void pop(){
        if (top==NULL||top->next==NULL){
            cout<<"Cannot go back"<<endl;
            return;
        }

        Node* temp=top;
        top=top->next;
        delete temp;

        cout<<"Current page"<<top->page<<endl;
    }

    void peek(){
        if(top==NULL){
            cout<<"No page open"<<endl;
        }
        else{
            cout<<"Current page"<<top->page<<endl;
        }
    }

    void display(){
        if(top==NULL){
            cout<<"History is empty"<<endl;
            return;
        }

        cout<<"Browser History"<<endl;

        Node* temp=top;

        while(temp!=NULL){
            cout<<temp->page<<endl;
            temp=temp->next;
        }
    }

    ~Stack(){
        while(top!=NULL){
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }
};

int main(){
    Stack browser;
    int choice;
    string page;

    do {
        cout<<"\nBrowser Menu"<<endl;
        cout<<"1. Visit Page"<<endl;
        cout<<"2. Back"<<endl;
        cout<<"3. Current Page"<<endl;
        cout<<"4. History"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<"Enter your choice";
        cin>>choice;

        switch (choice){
        case 1:
            cout<<"Enter page name";
            cin>>page;
            browser.push(page);
            break;

        case 2:
            browser.pop();
            break;

        case 3:
            browser.peek();
            break;

        case 4:
            browser.display();
            break;

        case 5:
            cout<<"Exiting browser"<<endl;
            break;

        default:
            cout<<"Invalid choice"<<endl;
        }

    } while(choice!=5);

    return 0;
}