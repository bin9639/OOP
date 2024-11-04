#include <iostream>
#include "TamGiac.h"
using namespace std;

int main() {
    float x1, y1, x2, y2, x3, y3;
    float goc, khoangCach;

    // Nhập tọa độ 3 đỉnh của tam giác
    cout << "Nhap toa do 3 diem cua tam giac (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Tạo 3 đối tượng Diem từ các tọa độ đã nhập
    Diem A(x1, y1), B(x2, y2), C(x3, y3);

    // Tạo đối tượng TamGiac với 3 đỉnh
    TamGiac tg(A, B, C);

    // Nhập hướng tịnh tiến và khoảng cách
    cout << "Nhap huong tịnh tien (do): ";
    cin >> goc;
    cout << "Nhap khoang cach tịnh tien: ";
    cin >> khoangCach;

    // Tịnh tiến tam giác
    tg.TinhTien(goc, khoangCach);

    // Xuất thông tin tam giác sau khi tịnh tiến
    cout << "Toa do 3 diem cua tam giac sau khi tinh tien:\n";
    tg.Xuat();

    return 0;
}
