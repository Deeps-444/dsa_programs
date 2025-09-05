#include <iostream>
using namespace std;

int maxSize = 22; // Maximum size of the stack

class node {
public:
    int data;
    node* down;

    node(int x) {
        data = x;
        down = NULL;
    }
};

class stack {
    node* top;
    int count; // To keep track of stack size
public:
    stack() {
        top = NULL;
        count = 0;
    }

    void push(int x);
    void pop();
    bool isEmpty() {
        return top == NULL;
    }
    bool isFull() {
        return count == maxSize;
    }
};

void stack::push(int v) {
    node* newnode = new node(v);
    if (isFull()) {
        cout << "Stack Overflow!!" << endl;
        return;
    }
    if (isEmpty()) {
        top = newnode;
    } else {
        newnode->down = top;
        top = newnode;
    }
    count++;  // Increment stack size
    cout << v << " pushed into the stack." << endl;
}

void stack::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!!" << endl;
        return;
    }
    cout << "Popped value: " << top->data << endl;
    node* temp = top;
    top = temp->down;
    delete temp;
    count--;  // Decrement stack size
}

int main() {
    stack s; // Create a stack object
    int n, p;

    do {
        cout << "Enter data: ";
        cin >> n;
        s.push(n);  // Push data onto the stack

        cout << "Enter 1 to continue adding, 0 to stop: ";
        cin >> p;
    } while (p == 1);

    // Example of popping an element
    s.pop();

    return 0;
}

