#include <iostream>
using namespace std;

// Định nghĩa cấu trúc nút của cây
struct Node {
    int data; // Giá trị của nút
    Node* left; // Con trái
    Node* right; // Con phải
    Node(int val) { data = val; left = nullptr; right = nullptr; } // Khởi tạo nút mới
};

// Lớp MinHeap để quản lý cây Heap
class MinHeap {
private:
    int heap[100]; // Mảng để lưu trữ heap
    int size; // Kích thước hiện tại của heap
    Node* root; // Gốc của cây

    // Hàm điều chỉnh heap từ chỉ số i
    void heapify(int i) {
        int smallest = i; // Giả sử nút nhỏ nhất là i
        int left = 2 * i + 1; // Chỉ số con trái
        int right = 2 * i + 2; // Chỉ số con phải
        if (left < size && heap[left] < heap[smallest]) smallest = left; // Kiểm tra con trái
        if (right < size && heap[right] < heap[smallest]) smallest = right; // Kiểm tra con phải
        if (smallest != i) { // Nếu không phải nút nhỏ nhất
            swap(heap[i], heap[smallest]); // Đổi chỗ
            heapify(smallest); // Đệ quy điều chỉnh lại
        }
    }

    // Hàm xây dựng cây nhị phân từ mảng heap
    Node* buildTree(int i) {
        if (i >= size) return nullptr; // Nếu vượt quá kích thước heap thì trả về null
        Node* node = new Node(heap[i]); // Tạo một nút mới từ giá trị trong heap
        node->left = buildTree(2 * i + 1); // Gọi đệ quy để tạo cây con trái
        node->right = buildTree(2 * i + 2); // Gọi đệ quy để tạo cây con phải
        return node; // Trả về nút đã tạo
    }

    // Duyệt cây theo kiểu Inorder
    void inorderTraversal(Node* node) {
        if (!node) return; // Nếu nút rỗng thì dừng lại
        inorderTraversal(node->left); // Duyệt cây con trái
        cout << node->data << " "; // In giá trị của nút
        inorderTraversal(node->right); // Duyệt cây con phải
    }

public:
    // Hàm khởi tạo MinHeap
    MinHeap() { size = 0; root = nullptr; }

    // Chèn một giá trị vào heap
    void insert(int val) {
        heap[size] = val; // Đưa giá trị vào cuối mảng
        int i = size; // Lấy chỉ số của phần tử vừa thêm
        size++; // Tăng kích thước heap
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) { // Kiểm tra và duy trì tính chất Min Heap
            swap(heap[i], heap[(i - 1) / 2]); // Đổi chỗ nếu cần
            i = (i - 1) / 2; // Cập nhật vị trí để tiếp tục kiểm tra
        }
    }

    // Xây dựng Min Heap từ mảng
    void buildHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) { // Bắt đầu từ nút cha cuối cùng
            heapify(i); // Điều chỉnh từng nút
        }
        root = buildTree(0); // Xây dựng cây từ heap
    }

    // Hàm gọi duyệt cây theo Inorder
    void inorder() {
        inorderTraversal(root); // Gọi hàm duyệt
        cout << endl; // Xuống dòng sau khi in xong
    }

    // Hàm xóa phần tử trong heap
    void deleteElement(int val) {
        int indexToDelete = -1;

        // Tìm chỉ số của phần tử cần xóa
        for (int i = 0; i < size; i++) {
            if (heap[i] == val) {
                indexToDelete = i;
                break;
            }
        }

        if (indexToDelete == -1) {
            cout << "Không tìm thấy phần tử " << val << " để xóa." << endl;
            return;
        }

        // Đưa phần tử cuối cùng vào vị trí phần tử cần xóa
        heap[indexToDelete] = heap[size - 1];
        size--; // Giảm kích thước của heap

        // Tiến hành heapify từ vị trí xóa
        heapify(indexToDelete);

        // Sau khi xóa, xây dựng lại heap để đảm bảo tính chất Min Heap
        buildHeap();
    }
};

// Hàm chính
int main() {
    MinHeap heap; // Tạo một đối tượng MinHeap
    int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Mảng chứa các phần tử đầu vào

    // 1. Chèn các phần tử vào heap ban đầu
    for (int val : arr) { // Lặp qua từng phần tử trong mảng
        heap.insert(val); // Chèn vào heap
    }
    heap.buildHeap(); // Xây dựng Min Heap
    cout << "Cây Min Heap ban đầu: ";
    heap.inorder(); // Gọi hàm duyệt inorder

    // 2. Chèn các phần tử mới vào heap
    heap.insert(14); // Chèn phần tử 14
    heap.insert(0);  // Chèn phần tử 0
    heap.insert(35); // Chèn phần tử 35

    // Xây dựng lại Min Heap sau khi thêm phần tử
    heap.buildHeap();
    cout << "Cây Min Heap sau khi chèn các phần tử 14, 0, 35: ";
    heap.inorder(); // Gọi hàm duyệt inorder sau khi chèn thêm phần tử

    // 3. Xóa các phần tử 6, 13, 35 ngay sau khi thao tác chèn
    heap.deleteElement(6);  // Xóa phần tử 6
    heap.deleteElement(13); // Xóa phần tử 13
    heap.deleteElement(35); // Xóa phần tử 35

    cout << "Cây Min Heap sau khi xóa các phần tử 6, 13, 35: ";
    heap.inorder(); // Gọi hàm duyệt inorder sau khi xóa các phần tử

    return 0;
}

