#include <iostream>
#include "ThiSinh.h"
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    cin.ignore(); // Xử lý bỏ ký tự xuống dòng thừa

    ThiSinh* ds = new ThiSinh[n]; // Tạo mảng động lưu thí sinh

    // Nhập thông tin các thí sinh
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }

    cout << "\nThong tin cac thi sinh co tong diem > 15:\n";
    for (int i = 0; i < n; ++i) {
        if (ds[i].Tong() > 15) {
            ds[i].Xuat();
            cout << "Tong diem: " << ds[i].Tong() << "\n\n";
        }
    }

    // Tìm thí sinh có điểm cao nhất
    int idxMax = 0;
    for (int i = 1; i < n; ++i) {
        if (ds[i].Tong() > ds[idxMax].Tong()) {
            idxMax = i;
        }
    }

    cout << "Thi sinh co tong diem cao nhat:\n";
    ds[idxMax].Xuat();
    cout << "Tong diem: " << ds[idxMax].Tong() << endl;

    delete[] ds; // Giải phóng bộ nhớ
    return 0;
}
