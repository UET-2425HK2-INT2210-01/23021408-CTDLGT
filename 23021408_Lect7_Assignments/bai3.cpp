#include <iostream>
using namespace std;

// Hàm đệ quy tính GCD
int gcd(int x, int y) {
    if (y == 0)  // Điều kiện dừng của đệ quy
        return x;
    return gcd(y, x % y);  // Đệ quy với x = y, y = x % y
}

int main() {
    int x, y;
    cin >> x >> y;

    cout <<  gcd(x, y) << endl;
    return 0;
}

