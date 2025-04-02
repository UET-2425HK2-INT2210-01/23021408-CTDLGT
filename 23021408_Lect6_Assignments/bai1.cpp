#include <iostream>
using namespace std;

// Định nghĩa một node trong cây nhị phân tìm kiếm
struct Node {
    int data;     // Dữ liệu của node
    Node* left;   // Con trỏ trỏ đến node con bên trái
    Node* right;  // Con trỏ trỏ đến node con bên phải

    // Constructor để khởi tạo node với giá trị val
    Node(int val) {
        data = val;      // Gán giá trị cho data của node
        left = nullptr;  // Khởi tạo con trỏ left là nullptr (node con bên trái)
        right = nullptr; // Khởi tạo con trỏ right là nullptr (node con bên phải)
    }
};

// Lớp BinarySearchTree để quản lý cây nhị phân tìm kiếm
class BinarySearchTree {
public:
    Node* root; // Con trỏ trỏ đến gốc của cây BST

    // Constructor khởi tạo cây rỗng
    BinarySearchTree() {
        root = nullptr; // Cây rỗng, nên root = nullptr
    }

    // Hàm chèn một giá trị vào BST
    void insert(int val) {
        root = insertRec(root, val); // Gọi hàm đệ quy insertRec để chèn giá trị vào cây
    }

    // Hàm duyệt cây theo kiểu Inorder
    void inOrder() {
        inOrderRec(root);  // Gọi hàm đệ quy inOrderRec để duyệt cây theo thứ tự trung tố
        cout << endl;      // In một dòng mới sau khi duyệt cây xong
    }

    // Hàm xóa một giá trị khỏi cây
    void deleteNode(int val) {
        root = deleteRec(root, val); // Gọi hàm đệ quy deleteRec để xóa giá trị khỏi cây
    }

private:
    // Hàm đệ quy để chèn giá trị vào BST
    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {  // Nếu cây rỗng (node == nullptr)
            return new Node(val);  // Tạo một node mới với giá trị val và trả về
        }

        // Nếu giá trị nhỏ hơn node hiện tại, tiếp tục chèn vào cây con bên trái
        if (val < node->data) {
            node->left = insertRec(node->left, val); // Đệ quy chèn vào cây con bên trái
        } else { // Nếu giá trị lớn hơn hoặc bằng node hiện tại, chèn vào cây con bên phải
            node->right = insertRec(node->right, val); // Đệ quy chèn vào cây con bên phải
        }

        return node;  // Trả về node sau khi chèn xong
    }

    // Hàm đệ quy để duyệt cây theo kiểu Inorder
    void inOrderRec(Node* node) {
        if (node == nullptr) {  // Nếu node là nullptr, dừng lại
            return;
        }

        inOrderRec(node->left);  // Đệ quy duyệt cây con bên trái
        cout << node->data << " ";  // In giá trị của node hiện tại
        inOrderRec(node->right);  // Đệ quy duyệt cây con bên phải
    }

    // Hàm đệ quy để xóa một node khỏi BST
    Node* deleteRec(Node* node, int val) {
        if (node == nullptr) {  // Nếu node là nullptr, không có gì để xóa
            return node;
        }

        // Tìm node cần xóa
        if (val < node->data) {
            node->left = deleteRec(node->left, val);  // Tìm node cần xóa trong cây con bên trái
        } else if (val > node->data) {
            node->right = deleteRec(node->right, val); // Tìm node cần xóa trong cây con bên phải
        } else {  // Nếu node cần xóa đã được tìm thấy
            // Trường hợp 1: Node không có con cái
            if (node->left == nullptr && node->right == nullptr) {
                delete node;  // Xóa node
                node = nullptr;  // Đặt node thành nullptr
            }
            // Trường hợp 2: Node chỉ có một con
            else if (node->left == nullptr) {  // Node chỉ có con bên phải
                Node* temp = node;  // Lưu node cần xóa
                node = node->right; // Chuyển node hiện tại thành node con bên phải
                delete temp;  // Xóa node cũ
            } else if (node->right == nullptr) {  // Node chỉ có con bên trái
                Node* temp = node;  // Lưu node cần xóa
                node = node->left;  // Chuyển node hiện tại thành node con bên trái
                delete temp;  // Xóa node cũ
            }
            // Trường hợp 3: Node có hai con
            else {
                Node* temp = minValueNode(node->right);  // Tìm node nhỏ nhất trong cây con bên phải
                node->data = temp->data;  // Thay giá trị node cần xóa bằng node nhỏ nhất từ cây con phải
                node->right = deleteRec(node->right, temp->data);  // Xóa node nhỏ nhất đó
            }
        }

        return node;  // Trả về node sau khi xóa
    }

    // Hàm tìm node có giá trị nhỏ nhất trong cây con bên phải
    Node* minValueNode(Node* node) {
        Node* current = node;  // Bắt đầu từ node hiện tại
        while (current && current->left != nullptr) {  // Tìm node con trái cùng sâu nhất
            current = current->left;
        }
        return current;  // Trả về node có giá trị nhỏ nhất
    }
};

// Hàm main để chạy chương trình
int main() {
    BinarySearchTree tree;  // Khởi tạo cây nhị phân tìm kiếm

    // Mảng ban đầu chứa các giá trị để chèn vào cây
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int size = sizeof(values) / sizeof(values[0]);  // Tính số phần tử trong mảng

    // Chèn các giá trị ban đầu vào BST
    for (int i = 0; i < size; i++) {
        tree.insert(values[i]);  // Chèn từng giá trị vào cây
    }

    // In cây sau khi chèn danh sách ban đầu
    cout << "Cây sau khi chèn danh sách ban đầu: ";
    tree.inOrder();  // Duyệt cây theo thứ tự trung tố và in ra kết quả

    // Chèn thêm các giá trị mới vào cây
    int newValues[] = {14, 0, 35};
    int newSize = sizeof(newValues) / sizeof(newValues[0]);  // Tính số phần tử trong mảng mới

    for (int i = 0; i < newSize; i++) {
        tree.insert(newValues[i]);  // Chèn từng giá trị mới vào cây
    }

    // In cây sau khi chèn thêm các node mới
    cout << "Cây sau khi chèn thêm các node mới: ";
    tree.inOrder();  // Duyệt cây theo thứ tự trung tố và in ra kết quả

    // Xóa các node với giá trị 6, 13, 35
    tree.deleteNode(6);  // Xóa node có giá trị 6
    tree.deleteNode(13); // Xóa node có giá trị 13
    tree.deleteNode(35); // Xóa node có giá trị 35

    // In cây sau khi xóa các node
    cout << "Cây sau khi xóa các node: ";
    tree.inOrder();  // Duyệt cây theo thứ tự trung tố và in ra kết quả

    return 0;
}
