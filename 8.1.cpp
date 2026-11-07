#include <iostream>
using namespace std;

const int MAX=5;        
int stk[MAX];             
int top=-1;             

bool isEmpty(){
    return top==-1;
}

bool isFull(){
    return top==MAX-1;
}

void push(int x){
    if (isFull()){
        cout<<"Stack Overflow: cannot push"<<x<<endl;
    } else {
        top++;
        stk[top]=x;
        cout<<x<<"pushed successfully"<<endl;
    }
}

void pop(){
    if (isEmpty()){
        cout<<"Stack Underflow: nothing to pop"<<endl;
    } else {
        cout<<"Popped"<<stk[top]<<endl;
        top--;
    }
}


int search(int x){
    if (isEmpty()){
        return -1;
    }
    int position=1;
    
    for(int i=top; i>=0; i--){
        if (stk[i]==x) {
            return position;
        }
        position++;
    }
    return -1; 
}

void display() {
    if (isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"TOP"<<endl;
    for(int i=top; i>=0; i--){
        cout<<"["<<i<<"]"<<stk[i]<<endl;
    }
    cout<<"BOTTOM"<<endl;
}

int main() {
    cout<<"=== 1. Pushing 5 elements into the stack ==="<<endl;
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    cout<<"\n=== 2.Trying to push a 6th element (Testing Overflow) ==="<<endl;
    push(60);

    cout<<"\n=== Current Stack State ==="<<endl;
    display();

    cout<<"\n===3.Testing Search Function==="<<endl;
    int valPresent=30;
    int valAbsent=99;
    
    int pos1=search(valPresent);
    if(pos1!=-1)
        cout<<"Element"<<valPresent<<"is found at position"<<pos1<<"from the top"<<endl;
    else
        cout<<"Element"<<valPresent<<"is not in the stack"<<endl;

    int pos2=search(valAbsent);
    if(pos2!=-1)
        cout<<"Element"<<valAbsent<<"is found at position"<<pos2<<"from the top"<<endl;
    else
        cout<<"Element"<<valAbsent<<"is not present in the stack (returns -1)."<<endl;

    cout<<"\n=== 4. Popping all items ==="<<endl;
    pop();
    pop(); 
    pop(); 
    pop(); 
    pop(); 

    cout<<"\n===5. Trying to pop from an empty stack(Testing Underflow)==="<< endl;
    pop();

    return 0;
}