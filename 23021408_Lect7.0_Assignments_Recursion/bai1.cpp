#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 1) return 1; // n = 1 trả về 1
    return n + sum(n-1); // cộng n với tổng(n-1)
}

int main() {
    int n; cin >> n;
    cout << sum(n);
    return 0;
}
