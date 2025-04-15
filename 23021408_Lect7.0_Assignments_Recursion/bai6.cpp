#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 0) return 0; // n = 0 trả về 0
    return n % 10 + sum(n/10); // chữ số cuối cùng cộng với tổng các chữ số còn lại
}

int main() {
    int n; cin >> n;
    cout << sum(n);
    return 0;
}

