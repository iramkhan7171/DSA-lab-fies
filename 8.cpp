#include <iostream>
using namespace std;
 
const int MAX = 5;       
int stk[MAX];           
int top = -1;            
 
bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }
int  size()    { return top + 1; }
void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow: cannot push " << x << endl;
    } else {
        top++;            
        stk[top] = x;    
        cout << x << " pushed." << endl;
    }
}
 
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow: nothing to pop" << endl;
    } else {
        cout << "Popped: " << stk[top] << endl;
        top--;           
    }
}
 
void peek() {
    if (isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Top element: " << stk[top] << endl;
}
 
void display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "--- TOP ---" << endl;
    for (int i = top; i >= 0; i--)
        cout << "[" << i << "] " << stk[i] << endl;
    cout << "-- BOTTOM --" << endl;
}
 
int main() {
    int choice, value;
    do {
        cout << "\n1.Push  2.Pop  3.Peek  4.Display  5.Size  0.Exit\n";
        cout << "Choice: ";
        cin >> choice;
 
        switch (choice) {
            case 1: cout << "Value: "; cin >> value; push(value); break;
            case 2: pop();     break;
            case 3: peek();    break;
            case 4: display(); break;
            case 5: cout << "Size = " << size() << endl; break;
            case 0: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice" << endl;
        }
    } while (choice != 0);
    return 0;
}
