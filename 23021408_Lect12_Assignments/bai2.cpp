#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc cạnh gồm hai đỉnh u, v và trọng số w
struct Edge {
    int u, v, w;
};

// Hàm so sánh hai cạnh theo yêu cầu đề:
// Sắp xếp theo trọng số tăng dần,
// Nếu trọng số bằng nhau thì so sánh u,
// Nếu u bằng nhau thì so sánh v
bool edgeCompare(const Edge &a, const Edge &b) {
    if (a.w != b.w) return a.w < b.w;
    if (a.u != b.u) return a.u < b.u;
    return a.v < b.v;
}

// Hàm tìm gốc (đại diện) của một đỉnh u trong DSU (Disjoint Set Union)
// Có sử dụng nén đường đi (path compression) để tối ưu
int find(int u, vector<int> &parent) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent); // Gán cha của u là gốc
    return parent[u];
}

// Hàm hợp nhất hai tập chứa u và v trong DSU
void unite(int u, int v, vector<int> &parent) {
    int pu = find(u, parent); // Tìm gốc của u
    int pv = find(v, parent); // Tìm gốc của v
    if (pu != pv)
        parent[pu] = pv;      // Gộp u vào tập của v
}

int main() {
    ifstream input("connection.txt");   // Mở file đầu vào
    ofstream output("connection.out");  // Mở file đầu ra

    int n, m;             // n: số máy tính, m: số cạnh kết nối
    input >> n >> m;      // Đọc số đỉnh và số cạnh từ file

    vector<Edge> edges(m); // Khai báo danh sách cạnh

    // Đọc m cạnh từ file
    for (int i = 0; i < m; i++) {
        int u, v, w;
        input >> u >> v >> w;         // Đọc cạnh từ file: u, v, w
        if (u > v) swap(u, v);        // Đảm bảo u < v để thống nhất sắp xếp
        edges[i] = {u, v, w};         // Lưu vào danh sách cạnh
    }

    // Sắp xếp các cạnh theo quy tắc đề bài
    sort(edges.begin(), edges.end(), edgeCompare);

    // Khởi tạo DSU với mỗi đỉnh là cha của chính nó
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int totalCost = 0;           // Tổng chi phí ban đầu = 0
    vector<Edge> mst;            // Danh sách cạnh của cây khung nhỏ nhất

    // Thuật toán Kruskal: duyệt qua các cạnh đã sắp xếp
    for (Edge e : edges) {
        // Nếu hai đỉnh u và v chưa cùng tập (chưa nối với nhau)
        if (find(e.u, parent) != find(e.v, parent)) {
            unite(e.u, e.v, parent);  // Nối hai đỉnh
            mst.push_back(e);         // Thêm cạnh vào cây khung
            totalCost += e.w;         // Cộng chi phí vào tổng
        }
    }

    // Sắp xếp lại danh sách cạnh trong MST để đúng thứ tự yêu cầu
    sort(mst.begin(), mst.end(), edgeCompare);

    // Ghi kết quả ra file output
    output << totalCost << endl;       // Dòng đầu là tổng chi phí
    for (Edge e : mst) {
        output << e.u << " " << e.v << " " << e.w << endl; // Mỗi dòng là một cạnh
    }

    input.close();  // Đóng file input
    output.close(); // Đóng file output
    return 0;
}
