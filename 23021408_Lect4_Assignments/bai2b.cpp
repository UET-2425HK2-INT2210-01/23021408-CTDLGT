#include <iostream>
using namespace std;

const int TABLE_SIZE = 11;
int hashTable[TABLE_SIZE];
bool occupied[TABLE_SIZE] = {false};

int hashFunction(int key) {
    return (2 * key + 5) % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    while (occupied[index]) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
    occupied[index] = true;
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        if (occupied[i]) {
            cout << hashTable[i];
        } else {
            cout << "[empty]";
        }
        cout << endl;
    }
}

int main() {
    int n, key;
    cout << "Enter the number of keys: ";
    cin >> n;
    cout << "Enter the keys: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> key;
        insert(key);
    }

    displayHashTable();
    return 0;
}

