// Cấu trúc Node:  
//     Thuộc tính: data, next  
//     Hàm khởi tạo(value): data ← value, next ← null  

// Lớp Stack:  
//     Thuộc tính: top, size ← null, 0  

//     Hàm isEmpty():  
//         Trả về (top == null)  

//     Hàm push(value):  
//         newNode ← Node(value)  
//         newNode.next ← top  
//         top ← newNode  
//         size++  

//     Hàm pop():  
//         Nếu isEmpty(): In "Rỗng", Trả về  
//         temp ← top  
//         top ← top.next  
//         Xóa temp  
//         size--  

//     Hàm peek():  
//         Nếu isEmpty(): In "Rỗng", Trả về -1  
//         Trả về top.data  

//     Hàm display():  
//         Nếu isEmpty(): In "Rỗng", Trả về  
//         temp ← top  
//         Trong khi temp: In temp.data, temp ← temp.next  


#include <iostream>
using namespace std;

// Node của danh sách liên kết
struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    // Kiểm tra ngăn xếp có rỗng không - O(1)
    bool isEmpty() {
        return top == nullptr;
    }

    // Thêm phần tử vào đỉnh ngăn xếp - O(1)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Loại bỏ phần tử khỏi đỉnh ngăn xếp - O(1)
    void pop() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // Lấy phần tử trên đỉnh ngăn xếp mà không xóa - O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng" << endl;
            return -1;
        }
        return top->data;
    }

    // Hiển thị ngăn xếp - O(n)
    void display() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng" << endl;
            return;
        }
        cout << "Ngăn xếp: ";
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


