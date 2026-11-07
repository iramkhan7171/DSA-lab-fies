#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string word;
    Node* next;

    Node(string w) {
        word = w;
        next = NULL;
    }
};

class Stack {
    Node* top;
    int count;

public:
    Stack() {
        top = NULL;
        count = 0;
    }

    void push(string word) {
        Node* newNode = new Node(word);
        newNode->next = top;
        top = newNode;

        count++;

        cout << "Typed: " << word << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Nothing to undo" << endl;
            return;
        }

        Node* temp = top;

        cout << "Undone: " << temp->word << endl;

        top = top->next;
        delete temp;

        count--;

        cout << "Word count: " << count << endl;
    }

    void peek() {
        if (top == NULL) {
            cout << "Editor is empty" << endl;
        }
        else {
            cout << "Last word: " << top->word << endl;
        }
    }

    int size() {
        return count;
    }

    void display() {
        if (top == NULL) {
            cout << "Editor is empty" << endl;
            return;
        }

        cout << "Words in editor: ";

        Node* temp = top;

        while (temp != NULL) {
            cout << temp->word << " ";
            temp = temp->next;
        }

        cout << endl;
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
    Stack editor;
    int choice;
    string word;

    do {
        cout << "\n--- Text Editor Menu ---" << endl;
        cout << "1. Type Word" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Last Word" << endl;
        cout << "4. Word Count" << endl;
        cout << "5. Display Words" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            cin >> word;
            editor.push(word);
            break;

        case 2:
            editor.pop();
            break;

        case 3:
            editor.peek();
            break;

        case 4:
            cout << "Word count: " << editor.size() << endl;
            break;

        case 5:
            editor.display();
            break;

        case 6:
            cout << "Exiting editor..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}