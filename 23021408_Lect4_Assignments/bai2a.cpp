#include<iostream>
using namespace std;

const int TABLE_SIZE=11;
int* hashTable[TABLE_SIZE], countKeys[TABLE_SIZE]={};

int hashFunction(int key) {
    return (2*key+5) % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int newSize = countKeys[index]+1;
    int* newArray = new int[newSize];

    for(int i=0 ;i<countKeys[index];i++) newArray[i]=hashTable[index][i];
    newArray[countKeys[index]]=key;

    if(countKeys[index]> 0) delete[] hashTable[index];

    hashTable[index] = newArray;
    countKeys[index] ++;
}

void displayHashTable() {
    for(int i=0; i<TABLE_SIZE; i++) {
        cout<<"Index "<< i <<": ";
        if(countKeys[i]>0) {
            for(int j=0;j<countKeys[i];j++) {
                cout<<hashTable[i][j];
                if(j<countKeys[i]-1) cout<<" -> ";
            }
        }
        cout<<endl;
    }
}

void freeMemory() {
    for(int i=0;i<TABLE_SIZE;i++) if(countKeys[i]>0) delete[] hashTable[i];
}

int main() {
    int n,key;
    cout<<"Enter the number of keys: ";
    cin>>n;
    cout<<"Enter the keys: " << endl;
    for(int i=0;i<n;i++) {
        cin>>key;
        insert(key);
    }
    displayHashTable();
    freeMemory();
    return 0;
}
