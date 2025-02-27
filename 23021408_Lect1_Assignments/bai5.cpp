#include <iostream>
using namespace std;

int main() {
    double a[5];

    for (int i = 0;i < 5;i++) {
        cin >> a[i];
    }

    double maxNum = a[0], minNum = a[0];

    for (int i = 1;i < 5;i++) {
        if (a[i] > maxNum) maxNum = a[i];
        if (a[i] < minNum) minNum = a[i];
    }

    cout << maxNum + minNum;

    return 0;
}
