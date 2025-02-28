#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void printStack() {
        Node* temp = top;
        if (temp == nullptr) return;

        int arr[1000], idx = 0;
        while (temp != nullptr) {
            arr[idx++] = temp->data;
            temp = temp->next;
        }

        for (int i = idx - 1; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) cout << " ";
        }
    }
};

int main() {
    int n;
    cin >> n;
    Stack s;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (command == "pop") {
            s.pop();
        }
    }

    s.printStack();
    return 0;
}
