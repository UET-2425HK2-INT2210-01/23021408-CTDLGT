#include <iostream>
using namespace std;

// Hàm đệ quy để sinh các số nhị phân
void generateBinary(int n, string binary) {
    // Nếu độ dài của chuỗi đạt n, in ra kết quả và kết thúc nhánh đệ quy này
    if (binary.length() == n) {
        cout << binary << endl;
        return;
    }

    // Gọi đệ quy để thêm '0' và '1'
    generateBinary(n, binary + "0");
    generateBinary(n, binary + "1");
}

int main() {
    int n;
    cin >> n;

    // Gọi hàm sinh dãy nhị phân bắt đầu với chuỗi rỗng
    generateBinary(n, "");

    return 0;
}

