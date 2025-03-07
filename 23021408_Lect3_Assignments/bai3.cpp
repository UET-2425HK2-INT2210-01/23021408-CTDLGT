// Lớp Queue:
//     Thuộc tính:
//         arr: mảng lưu trữ phần tử
//         front: chỉ số đầu hàng đợi
//         rear: chỉ số cuối hàng đợi
//         capacity: sức chứa tối đa
//         size: số phần tử hiện có

//     Hàm Constructor(cap):
//         capacity ← cap
//         arr ← cấp phát mảng có kích thước capacity
//         front ← 0
//         rear ← -1
//         size ← 0

//     Hàm isEmpty(): // Kiểm tra hàng đợi rỗng - O(1)
//         Trả về (size == 0)

//     Hàm isFull(): // Kiểm tra hàng đợi đầy - O(1)
//         Trả về (size == capacity)

//     Hàm enqueue(value): // Thêm phần tử vào hàng đợi - O(1)
//         Nếu isFull() thì:
//             In "Hàng đợi đầy"
//             Trả về
//         rear ← (rear + 1) % capacity
//         arr[rear] ← value
//         size++

//     Hàm dequeue(): // Loại bỏ phần tử đầu tiên - O(1)
//         Nếu isEmpty() thì:
//             In "Hàng đợi rỗng"
//             Trả về
//         front ← (front + 1) % capacity
//         size--

//     Hàm peek(): // Lấy phần tử đầu hàng đợi mà không xóa - O(1)
//         Nếu isEmpty() thì:
//             In "Hàng đợi rỗng"
//             Trả về -1
//         Trả về arr[front]

//     Hàm display(): // Hiển thị hàng đợi - O(n)
//         Nếu isEmpty() thì:
//             In "Hàng đợi rỗng"
//             Trả về
//         In "Hàng đợi:"
//         Lặp i từ 0 đến size - 1:
//             In arr[(front + i) % capacity]

//     Hàm freeMemory():
//         Giải phóng mảng arr


#include <iostream>
using namespace std;

class Queue {
private:
    int *arr, front, rear, capacity, size;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Kiểm tra hàng đợi có rỗng không - O(1)
    bool isEmpty() {
        return size == 0;
    }

    // Kiểm tra hàng đợi có đầy không - O(1)
    bool isFull() {
        return size == capacity;
    }

    // Thêm phần tử vào cuối hàng đợi - O(1)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Hàng đợi đầy " << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    // Loại bỏ phần tử đầu tiên - O(1)
    void dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    // Lấy phần tử đầu hàng đợi mà không xóa - O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return -1;
        }
        return arr[front];
    }

    // Hiển thị hàng đợi - O(n)
    void display() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng " << endl;
            return;
        }
        cout << "Hàng đợi: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
    }

    void freeMemory() {
        delete[] arr;
    }
};

