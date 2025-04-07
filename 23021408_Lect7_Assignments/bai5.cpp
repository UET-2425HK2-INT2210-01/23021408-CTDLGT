#include <iostream>
using namespace std;

// Hàm đệ quy sinh hoán vị
void generatePermutations(string chosen, string remaining) {
    if (remaining.empty()) {  // Nếu không còn số nào để chọn, in kết quả
        cout << chosen << endl;
        return;
    }

    for (int i = 0; i < remaining.length(); i++) {
        // Chọn một số để thêm vào chuỗi kết quả
        char ch = remaining[i];
        string new_chosen = chosen + ch;  // Thêm vào chuỗi kết quả
        string new_remaining = remaining.substr(0, i) + remaining.substr(i + 1); // Loại bỏ số đã chọn

        // Gọi đệ quy
        generatePermutations(new_chosen, new_remaining);
    }
}

int main() {
    int n;
    cin >> n;

    string digits = "";
    for (int i = 1; i <= n; i++) {
        digits += to_string(i); // Tạo chuỗi "123..."
    }

    generatePermutations("", digits); // Gọi hàm đệ quy với chuỗi rỗng ban đầu
    return 0;
}

