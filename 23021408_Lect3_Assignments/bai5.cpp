// Lớp Stack:  
//     Thuộc tính: arr, top, capacity  

//     Hàm khởi tạo(size): top ← -1, capacity ← size, cấp phát arr  

//     Hàm isEmpty(): Trả về (top == -1)  
//     Hàm isFull(): Trả về (top == capacity - 1)  

//     Hàm push(value): Nếu isFull(): In "Đầy", Trả về  
//                      arr[++top] ← value  

//     Hàm pop(): Nếu isEmpty(): In "Rỗng", Trả về  
//                top--  

//     Hàm peek(): Nếu isEmpty(): In "Rỗng", Trả về -1  
//                 Trả về arr[top]  

//     Hàm display(): Nếu isEmpty(): In "Rỗng", Trả về  
//                    Lặp i từ top → 0: In arr[i]  


#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Kiểm tra ngăn xếp có rỗng không - O(1)
    bool isEmpty() {
        return top == -1;
    }

    // Kiểm tra ngăn xếp có đầy không - O(1)
    bool isFull() {
        return top == capacity - 1;
    }

    // Thêm phần tử vào đỉnh ngăn xếp - O(1)
    void push(int value) {
        if (isFull()) {
            cout << "Ngăn xếp đầy" << endl;
            return;
        }
        arr[++top] = value;
    }

    // Loại bỏ phần tử khỏi đỉnh ngăn xếp - O(1)
    void pop() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng" << endl;
            return;
        }
        top--;
    }

    // Lấy phần tử trên đỉnh ngăn xếp mà không xóa - O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng" << endl;
            return -1;
        }
        return arr[top];
    }

    // Hiển thị ngăn xếp - O(n)
    void display() {
        if (isEmpty()) {
            cout << "Ngăn xếp rỗng" << endl;
            return;
        }
        cout << "Ngăn xếp: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

