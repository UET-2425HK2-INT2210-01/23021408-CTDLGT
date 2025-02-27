#include <iostream>
using namespace std;

int main() {
    string name;
    cout << " ";
    getline (cin,name);
    reverse (name.begin(), name.end() );
    cout << " " << name;
    return 0;
}

