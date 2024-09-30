#include <iostream>
#include <vector>
using namespace std;

// Hàm kiểm tra mảng A có xuất hiện trong mảng B bắt đầu từ vị trí indexB hay không
bool isSubarray(const vector<int>& A, const vector<int>& B, int indexB) {
    for (int i = 0; i < A.size(); ++i) {
        if (indexB + i >= B.size() || A[i] != B[indexB + i]) {
            return false;
        }
    }
    return true;
}

// Hàm đếm số lần mảng A xuất hiện liên tiếp trong mảng B
int countSubarrayOccurrences(const vector<int>& A, const vector<int>& B) {
    int count = 0;
    for (int i = 0; i <= B.size() - A.size(); ++i) {
        if (isSubarray(A, B, i)) {
            ++count;
        }
    }
    return count;
}

int main() {
    // Nhập mảng A
    int nA;
    cout << "Nhập số phần tử của mảng A: ";
    cin >> nA;
    vector<int> A(nA);
    cout << "Nhập các phần tử của mảng A: ";
    for (int i = 0; i < nA; ++i) {
        cin >> A[i];
    }

    // Nhập mảng B
    int nB;
    cout << "Nhập số phần tử của mảng B: ";
    cin >> nB;
    vector<int> B(nB);
    cout << "Nhập các phần tử của mảng B: ";
    for (int i = 0; i < nB; ++i) {
        cin >> B[i];
    }

    // Đếm số lần mảng A xuất hiện trong mảng B
    int occurrences = countSubarrayOccurrences(A, B);
    cout << "Số lần mảng A xuất hiện trong mảng B là: " << occurrences << endl;

    return 0;
}
