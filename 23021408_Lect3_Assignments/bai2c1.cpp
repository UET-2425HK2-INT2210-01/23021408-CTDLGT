// power(n):  
//     result ← 1  
//     Lặp n lần: result ← result * 2  
//     Trả về result  

// main():  
//     Nhập n  
//     Xuất "2^", n, " = ", power(n)  


#include <iostream>
using namespace std;

long long power(int n) {
    long long result  = 1;
    for (int i = 0; i < n; i++) result *= 2;
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << "2^" << n << " = " << power(n);
    return 0;
}

//Độ phức tạp O(n)
