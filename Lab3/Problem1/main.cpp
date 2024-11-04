// main.cpp
#include "phanso.h"

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;
    cout << "Nhap phan so thu hai:\n";
    cin >> ps2;

    // Các phép toán
    cout << "Tong: " << ps1 + ps2 << endl;
    cout << "Hieu: " << ps1 - ps2 << endl;
    cout << "Tich: " << ps1 * ps2 << endl;
    cout << "Thuong: " << ps1 / ps2 << endl;

    // Các phép so sánh
    cout << "Phan so thu nhat " << (ps1 == ps2 ? "bang" : "khong bang") << " phan so thu hai\n";
    cout << "Phan so thu nhat " << (ps1 != ps2 ? "khac" : "khong khac") << " phan so thu hai\n";
    cout << "Phan so thu nhat " << (ps1 > ps2 ? "lon hon" : "khong lon hon") << " phan so thu hai\n";
    cout << "Phan so thu nhat " << (ps1 < ps2 ? "nho hon" : "khong nho hon") << " phan so thu hai\n";
    cout << "Phan so thu nhat " << (ps1 >= ps2 ? "lon hon hoac bang" : "khong lon hon hoac bang") << " phan so thu hai\n";
    cout << "Phan so thu nhat " << (ps1 <= ps2 ? "nho hon hoac bang" : "khong nho hon hoac bang") << " phan so thu hai\n";

    return 0;
}
