#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};
class Stack {
    Node* top;
public:
    Stack() {
        top = NULL;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (top == NULL) {
            return -1;
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }
    bool isEmpty() {
        return top == NULL;
    }
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main() {
    Stack s;
    int num;
    cout << "Enter number: ";
    cin >> num;
    if (num < 0) {
        cout << "Please enter a non-negative number." << endl;
    }
    else if (num == 0) {
        cout << "Binary: 0" << endl;
    }
    else {
        while (num > 0) {
            int remainder = num % 2;
            s.push(remainder);
            num = num / 2;
        }
        cout << "Binary: ";
        while (!s.isEmpty()) {
            cout << s.pop();
        }
        cout << endl;
    }
    return 0;
}