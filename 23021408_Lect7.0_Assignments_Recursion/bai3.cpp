#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 1) return 1; // n = 1 trả về 1
    if (n == 0) return 0; // n = 0 trả về 0
    return fibonacci(n-1) + fibonacci(n-2); // tính số fibonacci thứ n bằng cách cộng hai số trước đó
}

int main() {
    int n; cin >> n;
    cout << fibonacci(n);
    return 0;
}


