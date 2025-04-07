#include <iostream>
#include <fstream>

using namespace std;

// Khai báo mảng a (ma trận ban đầu), prefix (ma trận prefix sum), và temp (mảng tạm cho Kadane)
int a[1000][1000], prefix[1000][1000], temp[1000];

int main() {
    // Mở file đầu vào (matrix.txt) và đầu ra (matrix.out)
    ifstream input("matrix.txt");
    ofstream output("matrix.out");

    // Đọc kích thước ma trận m (số hàng) và n (số cột)
    int m, n;
    input >> m >> n;

    // Đọc các phần tử của ma trận vào mảng a
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            input >> a[i][j];
        }
    }

    // Tính ma trận prefix sum
    // prefix[i][j] lưu trữ tổng của ma trận con từ (1,1) đến (i,j)
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = a[i][j] + prefix[i - 1][j]; // Cộng giá trị ma trận với tổng của dòng trước đó
        }
    }

    // Khởi tạo giá trị maxSum với số rất nhỏ (dễ hiểu là -1000 ở đây)
    int maxSum = -1000, r1, c1, r2, c2;

    // Duyệt qua tất cả các cặp hàng (r1, r2)
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {

            // Tính tổng các cột từ hàng i đến hàng j
            for (int k = 1; k <= n; k++) {
                temp[k] = prefix[j][k] - prefix[i - 1][k]; // Cộng dồn giá trị các cột trong khoảng từ i đến j
            }

            // Áp dụng Kadane’s Algorithm trên mảng temp để tìm dãy con có tổng lớn nhất
            int sum = 0, localL = 1; // Khởi tạo giá trị sum và vị trí bắt đầu của dãy con

            // Duyệt qua các cột
            for (int k = 1; k <= n; k++) {
                // Nếu sum < 0, khởi tạo lại sum với giá trị hiện tại của temp[k]
                if (sum < 0) {
                    sum = temp[k];
                    localL = k; // Cập nhật vị trí bắt đầu dãy con
                } else {
                    sum += temp[k]; // Cộng thêm giá trị vào sum
                }

                // Nếu tổng hiện tại lớn hơn maxSum, cập nhật lại maxSum và tọa độ của hình chữ nhật
                if (sum > maxSum) {
                    maxSum = sum;
                    r1 = i; r2 = j;
                    c1 = localL; c2 = k;
                }
            }
        }
    }

    // In ra kết quả vào file đầu ra
    output << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl;

    // Đóng file đầu vào và đầu ra
    input.close();
    output.close();

    // Thông báo đã lưu kết quả vào file
    cout << "Đã lưu trong 'matrix.out' " << endl;

    return 0;
}
