// Cấu trúc Node:
//     data, next
//     Hàm khởi tạo(value): data ← value, next ← null

// Lớp Queue:
//     Thuộc tính: front, rear, size ← null, null, 0

//     Hàm isEmpty(): Trả về (size == 0)

//     Hàm enqueue(value):  
//         newNode ← Node(value)  
//         Nếu isEmpty(): front ← rear ← newNode  
//         Ngược lại: rear.next ← newNode, rear ← newNode  
//         size++

//     Hàm dequeue():  
//         Nếu isEmpty(): In "Hàng đợi rỗng", Trả về  
//         temp ← front, front ← front.next, Xóa temp, size--  
//         Nếu front == null: rear ← null  

//     Hàm peek():  
//         Nếu isEmpty(): In "Hàng đợi rỗng", Trả về -1  
//         Trả về front.data  

//     Hàm display():  
//         Nếu isEmpty(): In "Hàng đợi rỗng", Trả về  
//         temp ← front  
//         Trong khi temp: In temp.data, temp ← temp.next  


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = rear = nullptr;
        size = 0;
    }

    // Kiểm tra hàng đợi có rỗng không - O(1)
    bool isEmpty() {
        return size == 0;
    }

    // Thêm phần tử vào cuối hàng đợi - O(1)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Loại bỏ phần tử đầu tiên - O(1)
    void dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == nullptr) rear = nullptr;
    }

    // Lấy phần tử đầu hàng đợi mà không xóa - O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng" << endl;
            return -1;
        }
        return front->data;
    }

    // Hiển thị hàng đợi - O(n)
    void display() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng" << endl;
            return;
        }
        Node* temp = front;
        cout << "Hàng đợi: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
