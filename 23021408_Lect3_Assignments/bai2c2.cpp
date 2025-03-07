// power(n):  
//     Nếu n = 0:  
//         Trả về 1  
//     tmp ← power(n / 2)  
//     Nếu n chẵn:  
//         Trả về tmp * tmp  
//     Ngược lại:  
//         Trả về tmp * tmp * 2  

// main():  
//     Nhập n  
//     Xuất "2^", n, " = ", power(n)  


#include <iostream>
using namespace std;

long long power(int n) {
    if (n == 0) return 1;
    long long tmp = power(n / 2);
    if (n % 2 == 0) return tmp * tmp;
    return tmp * tmp * 2;
}

int main() {
    int n;
    cin >> n;
    cout << "2^" << n << " = " << power(n);
    return 0;
}

//Độ phức tạp O(logn)
