#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 1) return 1; // n = 1 trả về 1
    return n * factorial(n-1); // nhân n với giai thừa(n-1)
}

int main() {
    int n; cin >> n;
    cout << factorial(n);
    return 0;
}

