#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void search(int x) {
        Node* temp = head;
        int index = 1;

        while (temp) {
            if (temp->data == x) {
                cout << index << endl;
                return;
            }
            temp = temp->next;
            index++;
        }

        cout << "NO" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void printList() {
        Node* temp = head;

        while (temp) {
            cout << temp->data;
            if (temp->next) {
                cout << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList list;
    string command;
    int value;

    for (int i = 0; i < n; i++) {
        cin >> command;

        if (command == "append") {
            cin >> value;
            list.append(value);
        }
        else if (command == "search") {
            cin >> value;
            list.search(value);
        }
        else if (command == "reverse") {
            list.reverse();
            list.printList();
        }
    }

    return 0;
}
