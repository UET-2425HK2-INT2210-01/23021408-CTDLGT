#include <iostream>
using namespace std;

const int SIZE = 17;

struct Node {
    int key;
    Node* next;
};

class HashTable {
private:
    Node* table[SIZE];

    int hashFunction(int key) {
        return (key + 3) % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node{key, nullptr};

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i;
            Node* temp = table[i];

            if (temp == nullptr) {
                cout << endl;
                continue;
            }

            cout << " ";
            while (temp) {
                cout << temp->key;
                if (temp->next) cout << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node* temp = table[i];
            while (temp) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter integers:\n";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        hashTable.insert(key);
    }

    hashTable.display();

    return 0;
}
