#include <iostream>
using namespace std;

int dao_nguoc(int n, int rev = 0) {
    if (n == 0) return rev; // n = 0 trả về kết quả đảo ngược
    return dao_nguoc(n/10, rev*10 + n%10); // đảo ngược số bằng cách thêm chữ số cuối vào rev
}

int main() {
    int n; cin >> n;
    cout << dao_nguoc(n);
    return 0;
}


