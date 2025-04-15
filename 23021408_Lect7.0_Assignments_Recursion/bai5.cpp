#include <iostream>
using namespace std;

int dem(int n) {
    if (n == 0) return 0; // n = 0 trả về 0
    if (n < 10) return 1; // n < 10 trả về 1
    return 1 + dem(n/10); // chia n cho 10 và đếm thêm 1 chữ số
}

int main() {
    int n; cin >> n;
    cout << dem(n);
    return 0;
}

