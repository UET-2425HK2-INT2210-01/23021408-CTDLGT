#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

// Số đỉnh tối đa (giả sử n <= 100 theo đề)
const int MAX = 105;
// Giá trị "vô cực", chia nhỏ INT_MAX để tránh tràn khi cộng
const int INF = INT_MAX / 2;

// Ma trận khoảng cách giữa các cặp đỉnh
int dist[MAX][MAX];

// Ma trận truy vết đường đi ngắn nhất (nextNode[i][j] là đỉnh tiếp theo từ i để đi đến j)
int nextNode[MAX][MAX];

int main() {
    // Mở file đầu vào và đầu ra
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");

    int n, m, s, e;
    fin >> n >> m >> s >> e; // Đọc số đỉnh n, số cạnh m, đỉnh bắt đầu s và đỉnh kết thúc e

    // Khởi tạo ma trận khoảng cách và truy vết
    for (int i = 1; i <= n; ++i) {              // Duyệt qua tất cả đỉnh i
        for (int j = 1; j <= n; ++j) {          // Duyệt qua tất cả đỉnh j
            if (i == j) dist[i][j] = 0;         // Khoảng cách từ i đến chính nó là 0
            else dist[i][j] = INF;              // Khởi tạo khoảng cách vô cực cho các cặp khác
            nextNode[i][j] = -1;                // Chưa có truy vết đường đi
        }
    }

    // Đọc m cạnh có hướng và cập nhật trọng số và truy vết
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;               // Cạnh từ u đến v có độ bẩn (dirty level) d
        dist[u][v] = d;                   // Cập nhật khoảng cách từ u đến v
        nextNode[u][v] = v;               // Để truy vết, bước đầu từ u → v là đi đến v
    }

    // Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp đỉnh
    for (int k = 1; k <= n; ++k) {               // Thử qua từng đỉnh trung gian k
        for (int i = 1; i <= n; ++i) {           // Duyệt đỉnh bắt đầu i
            for (int j = 1; j <= n; ++j) {       // Duyệt đỉnh kết thúc j
                // Nếu đường đi i → k và k → j đều tồn tại, và đi qua k ngắn hơn
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // Cập nhật khoảng cách
                    nextNode[i][j] = nextNode[i][k];      // Cập nhật truy vết: đi từ i đến j thì bước đầu là đi từ i đến đỉnh tiếp theo trên đường đến k
                }
            }
        }
    }

    //In ra tổng dirty level từ s đến e và đường đi
    if (dist[s][e] >= INF) {
        // Không có đường đi từ s đến e
        fout << "INF\n";
        fout << "No path\n";
    } else {
        fout << dist[s][e] << '\n'; // In tổng độ bẩn (chi phí) nhỏ nhất từ s đến e

        // Truy vết đường đi từ s đến e
        vector<int> path;
        int curr = s;
        while (curr != e) {
            path.push_back(curr);             // Ghi nhận đỉnh hiện tại vào đường đi
            curr = nextNode[curr][e];         // Di chuyển đến đỉnh tiếp theo
            if (curr == -1) break;            // Không còn đường đi
        }
        path.push_back(e);                    // Thêm đỉnh kết thúc e

        // In ra đường đi (các đỉnh theo thứ tự)
        for (size_t i = 0; i < path.size(); ++i) {
            fout << path[i];
            if (i < path.size() - 1) fout << " ";
        }
        fout << '\n';
    }

    //In ma trận khoảng cách giữa tất cả các cặp đỉnh
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] >= INF)
                fout << "INF ";       // Nếu không có đường đi, in INF
            else
                fout << dist[i][j] << " "; // In độ bẩn ngắn nhất từ i đến j
        }
        fout << '\n';                 // Xuống dòng sau mỗi hàng
    }

    return 0;
}
