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

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) return;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void printQueue() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " ";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Queue q;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (command == "dequeue") {
            q.dequeue();
        }
    }

    q.printQueue();
    return 0;
}
