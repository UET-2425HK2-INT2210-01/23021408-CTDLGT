#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = nullptr; }
};

struct LinkedList {
    Node* head;
    LinkedList() { head = nullptr; }

    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* cur = head;
        for (int i = 0; cur != nullptr && i < p - 1; i++)
            cur = cur->next;
        if (cur == nullptr) return;
        newNode->next = cur->next;
        cur->next = newNode;
    }

    void remove(int p) {
        if (head == nullptr) return;
        if (p == 0) {
            head = head->next;
            return;
        }
        Node* cur = head;
        for (int i = 0; cur->next != nullptr && i < p - 1; i++)
            cur = cur->next;
        if (cur->next == nullptr) return;
        cur->next = cur->next->next;
    }

    void print() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++) {
        string op;
        int p, x;
        cin >> op >> p;
        if (op == "insert") {
            cin >> x;
            list.insert(p, x);
        } else if (op == "delete") {
            list.remove(p);
        }
    }
    list.print();
    return 0;
}
