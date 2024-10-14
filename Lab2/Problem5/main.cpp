#include <iostream>
#include "Diem.h"
using namespace std;

int main() {
    int x, n;
    int hoanh, tung;

    // Nhập tọa độ điểm ban đầu
    cout << "Nhap hoanh do: ";
    cin >> hoanh;
    cout << "Nhap tung do: ";
    cin >> tung;

    // Tạo đối tượng Diem với hoành độ và tung độ đã nhập
    Diem point(hoanh, tung);

    // Nhập số lượng chỉ thị
    cout << "Nhap so luong chi thi: ";
    cin >> n;

    // Xử lý từng chỉ thị
    for (int i = 0; i < n; ++i) {
        cout << "Nhap chi thi: ";
        cin >> x;

        if (x == 1) {
            point.NhanDoi();
        } else if (x == 2) {
            point.GanGocToaDo();
        } else if (x == 3) {
            int k, d;
            cout << "Nhap huong tinh tien k (0 theo x, != 0 theo y) va do tinh tien d: ";
            cin >> k >> d;
            point.TinhTien(k, d);
        }
    }

    // Xuất tọa độ điểm sau khi thực hiện các chỉ thị
    cout << "Toa do cuoi cung: ";
    point.Xuat();

    return 0;
}
