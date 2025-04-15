#include <iostream>
using namespace std;

int power(int x, int n) {
    if (n == 0) return 1; // n = 0 trả về 1
    return x * power(x, n - 1); // nhân x với x^(n-1)
}

int main() {
    int n, x; cin >> x >> n;
    cout << power(x, n);
    return 0;
}

