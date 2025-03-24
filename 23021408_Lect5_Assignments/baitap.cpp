#include <iostream>
using namespace std;


// Cấu trúc một nút trong cây
struct Node {
    int data;
    Node* left;     // Con trái
    Node* right;    // Con phải

    Node(int d) : data(d), left(nullptr), right(nullptr) {} // Hàm khởi tạo một nút mới với giá trị data
};

// Danh sách liên kết để lưu các nút của cây
struct NodeList {
    struct NodeItem {
        Node* node;  // Con trỏ đến nút trong cây
        NodeItem* next;  // Con trỏ đến phần tử tiếp theo trong danh sách

        // Hàm khởi tạo
        NodeItem(Node* n) : node(n), next(nullptr) {}
    };

    NodeItem* head; // Con trỏ đầu danh sách
    NodeList() : head(nullptr) {} // Khởi tạo danh sách rỗng

    // Hàm thêm một nút vào danh sách liên kết
    void insert(Node* node) {
        NodeItem* newItem = new NodeItem(node); // Tạo phần tử mới
        newItem->next = head; // Chèn vào đầu danh sách
        head = newItem; // Cập nhật head
    }

    // Tìm nút có giá trị data bằng value
    Node* find(int value) {
        NodeItem* temp = head;
        while (temp) {
            if (temp->node->data == value) return temp->node; // Nếu tìm thấy, trả về nút
            temp = temp->next;
        }
        return nullptr; // Không tìm thấy, trả về nullptr
    }
};

// Cấu trúc cây
struct Tree {
    NodeList nodeList; // Danh sách các nút trong cây
    int parent[100] = {0}; // Mảng lưu cha của từng nút
    bool isBinary = true; // Biến kiểm tra cây có phải nhị phân không

    // Hàm lấy hoặc tạo một nút mới
    Node* getNode(int data) {
        Node* node = nodeList.find(data); // Tìm nút trong danh sách
        if (!node) { // Nếu chưa có, tạo mới
            node = new Node(data);
            nodeList.insert(node); // Thêm vào danh sách
        }
        return node;
    }

    // Thêm cạnh u -> v vào cây
    void addEdge(int u, int v) {
        Node* parent = getNode(u); // Lấy nút cha
        Node* child = getNode(v);  // Lấy nút con

        // Kiểm tra nếu nút cha đã có 2 con thì đây không phải cây nhị phân
        if (!parent->left) parent->left = child;
        else if (!parent->right) parent->right = child;
        else isBinary = false; // Có hơn 2 con, vậy không phải cây nhị phân

        this->parent[v] = u; // Ghi nhớ cha của v
    }

    // Tìm gốc của cây  , không phải cha
    Node* findRoot(int n) {
        for (int i = 1; i <= n; i++) // Duyệt từ 1 đến N
            if (!parent[i]) return getNode(i); // Nếu không có cha, sẽ Là gốc
        return nullptr; // Không tìm thấy gốc
    }

    // Tính chiều cao của cây
    int getHeight(Node* root) {
        if (!root) return 0; // Cây rỗng → Chiều cao 0
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    // Duyệt theo Preorder
    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Duyệt theo Postorder
    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    // Duyệt theo Inorder
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    int N, M; // Số nút và số cạnh
    cin >> N >> M;

    Tree tree; // Khởi tạo cây

    // Nhập các cạnh của cây
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v); // Thêm cạnh vào cây
    }

    Node* root = tree.findRoot(N); // Xác định gốc cây

    cout << tree.getHeight(root) - 1 << endl; // In chiều cao của cây
    tree.preorder(root); cout << endl; // In Preorder
    tree.postorder(root); cout << endl; // In Postorder

    if (tree.isBinary) {
        tree.inorder(root); // Nếu là cây nhị phân, in Inorder
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl; // Không phải cây nhị phân thì in NOT BINART TREE
    }

    return 0;
}

