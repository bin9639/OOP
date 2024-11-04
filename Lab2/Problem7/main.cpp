#include "DaGiac.h"

int main() {
    DaGiac dagiac;

    // Nhập thông tin đa giác
    dagiac.Nhap();

    // Xuất thông tin đa giác
    dagiac.Xuat();

    // Tính và xuất diện tích
    cout << "Dien tich da giac: " << dagiac.DienTich() << endl;

    return 0;
}
