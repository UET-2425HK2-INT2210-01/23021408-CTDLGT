#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    string class_name;
};

const int MAX_STUDENTS = 1000;
Student students[MAX_STUDENTS];
int studentCount = 0;

void insertStudent(int id, string name, string class_name) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            students[i].name = name;
            students[i].class_name = class_name;
            return;
        }
    }
    students[studentCount++] = {id, name, class_name};
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            return;
        }
    }
}

string getStudentInfo(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return students[i].name + "," + students[i].class_name;
        }
    }
    return "NA,NA";
}

int main() {
    string command;
    while (cin >> command) {
        if (command == "Insert") {
            int id;
            string name, class_name;
            cin >> id;
            cin.ignore();
            getline(cin, name);
            getline(cin, class_name);
            insertStudent(id, name, class_name);
        } else if (command == "Delete") {
            int id;
            cin >> id;
            deleteStudent(id);
        } else if (command == "Infor") {
            int id;
            cin >> id;
            cout << getStudentInfo(id) << endl;
        }
    }
    return 0;
}
