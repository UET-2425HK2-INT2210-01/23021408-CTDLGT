#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

queue<int> q;

int n, m; // Số lượng đỉnh (n) và số lượng cạnh (m)
int a[1001][1001]; // Ma trận kề để biểu diễn đồ thị có hướng
int indegree[1001]; // Mảng lưu bậc vào của từng đỉnh
int result[1001]; // Mảng lưu kết quả thứ tự topo sau khi sắp xếp

int main() {
    ifstream input("jobs.txt"); // Mở file "jobs.txt" để đọc dữ liệu đầu vào
    ofstream output("jobs.out"); // Mở file "jobs.out" để ghi kết quả đầu ra

    input >> n >> m; // Đọc số lượng đỉnh và cạnh từ file

    for (int i = 0; i < m; i++) { // Duyệt qua m cạnh
        int u, v; // u là đỉnh bắt đầu, v là đỉnh kết thúc
        input >> u >> v; // Đọc cạnh từ file
        a[u][v] = 1; // Gán giá trị 1 vào ma trận kề tại vị trí u -> v
        indegree[v]++; // Tăng bậc vào của đỉnh v
    }

    for (int i = 1; i <= n; i++) { // Duyệt qua tất cả các đỉnh từ 1 đến n
        if (indegree[i] == 0) q.push(i); // Nếu đỉnh có bậc vào bằng 0, thêm vào hàng đợi
    }

    int idx = 0; // Chỉ số để lưu kết quả vào mảng result

    while (!q.empty()) { // Trong khi hàng đợi còn phần tử
        int u = q.front(); q.pop(); // Lấy đỉnh đầu tiên trong hàng đợi và loại bỏ nó
        result[idx++] = u; // Ghi đỉnh này vào kết quả topo

        for (int v = 1; v <= n; v++) { // Duyệt qua tất cả các đỉnh
            if (a[u][v]) { // Nếu tồn tại cạnh từ u đến v
                indegree[v]--; // Giảm bậc vào của đỉnh v
                if (indegree[v] == 0) q.push(v); // Nếu bậc vào bằng 0, thêm vào hàng đợi
            }
        }
    }

    if (idx < n) { // Nếu chưa xử lý đủ n đỉnh, nghĩa là có chu trình trong đồ thị
        output << "Graph has a cycle. Topological sort not possible."; // Thông báo không thể sắp xếp topo
    } else {
        for (int i = 0; i < n; i++) { // Ghi kết quả sắp xếp topo ra file
            output << result[i]; // Ghi từng đỉnh
            if (i < n - 1) output << " "; // Thêm dấu cách giữa các đỉnh (trừ đỉnh cuối)
        }
    }

    input.close(); // Đóng file input
    output.close(); // Đóng file output

    return 0;
}
