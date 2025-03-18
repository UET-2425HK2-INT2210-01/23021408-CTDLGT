#include <iostream>
using namespace std;

const int SIZE = 17;
const int EMPTY = -1;

class HashTable {
private:
    int table[SIZE];

    int hashFunction(int key) {
        return (key + 3) % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = EMPTY;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        while (table[index] != EMPTY) {
            index = (index + 1) % SIZE;
        }
        table[index] = key;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i;
            if (table[i] != EMPTY) {
                cout << "    " << table[i];
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter integers: " << endl;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        hashTable.insert(key);
    }

    hashTable.display();
    return 0;
}

