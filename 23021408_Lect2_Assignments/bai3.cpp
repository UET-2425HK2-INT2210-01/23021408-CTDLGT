#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int countTriplets() {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return 0;
        }

        int count = 0;
        Node* cur = head->next;
        while (cur->next != nullptr) {
            if (cur->prev->data + cur->data + cur->next->data == 0) {
                count++;
            }
            cur = cur->next;
        }
        return count;
    }
};

int main() {
    int n, x;
    cin >> n;
    DoublyLinkedList list;
    for (int i = 0; i < n; i++) {
        cin >> x;
        list.insert(x);
    }
    cout << list.countTriplets();
}
