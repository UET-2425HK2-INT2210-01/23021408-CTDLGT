#include <iostream>
using namespace std;

struct Node {
    int value, priority;
    Node* next;
    Node* prev;
    Node(int v, int p) : value(v), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() : head(nullptr) {}

    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);
        if (!head || head->priority < p) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }
        Node* cur = head;
        while (cur->next && cur->next->priority >= p) cur = cur->next;
        newNode->next = cur->next;
        if (cur->next) cur->next->prev = newNode;
        cur->next = newNode;
        newNode->prev = cur;
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void printQueue() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << "(" << cur->value << ", " << cur->priority << "); ";
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;
    string command;
    int x, p;
    while (n--) {
        cin >> command;
        if (command == "enqueue") {
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }
    pq.printQueue();
    return 0;
}
