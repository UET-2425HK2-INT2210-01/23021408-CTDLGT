#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const int MAX_N = 1000; // Khai báo số lượng phần tử tối đa (mảng tĩnh)
    int numbers[MAX_N];     // Mảng lưu các sốa nguyên đọc từ file
    int n = 0;              // Biến đếm số lượng phần tử đọc được
    int num;                // Biến tạm để lưu từng số khi đọc

    ifstream input("numbers.txt");     // Mở file đầu vào để đọc
    ofstream output("numbers.sorted"); // Mở file đầu ra để ghi

    // Kiểm tra xem file có mở được không
    if (!input || !output) {
        cout << "Khong mo duoc file!" << endl; // Thông báo lỗi nếu không mở được
        return 1; // Thoát chương trình với mã lỗi
    }

    // Đọc dữ liệu từ file cho đến khi hết
    while (input >> num) {
        numbers[n++] = num; // Gán giá trị vào mảng và tăng biến đếm
    }

    // Sắp xếp mảng bằng thuật toán nổi bọt (bubble sort)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                // Đổi chỗ 2 phần tử nếu sai thứ tự
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Ghi mảng đã sắp xếp ra file đầu ra
    for (int i = 0; i < n; ++i) {
        output << numbers[i]; // Ghi số vào file
        if (i != n - 1) output << " "; // Thêm dấu cách nếu không phải số cuối
    }

    input.close();  // Đóng file đầu vào
    output.close(); // Đóng file đầu ra

    // Thông báo hoàn thành
    cout << "Các số đã được sắp xếp, được lưu trong 'numbers.sorted' " << endl;

    return 0;
}
