
#include "DaGiac.h"
#include <cmath> // fabs

// Nhập thông tin đa giác
void DaGiac::Nhap() {
    do {
        cout << "Nhap so dinh cua da giac (n > 2): ";
        cin >> n;
    } while (n <= 2); // Kiểm tra số đỉnh hợp lệ

    dinh.resize(n); // Cấp phát không gian cho các đỉnh

    // Nhập từng tọa độ đỉnh
    for (int i = 0; i < n; ++i) {
        cout << "Nhap toa do dinh thu " << i + 1 << ": ";
        dinh[i].Nhap();
    }
}

// Xuất thông tin đa giác
void DaGiac::Xuat() const {
    cout << "Cac dinh cua da giac: ";
    for (const auto &d : dinh) {
        d.Xuat();
        cout << " ";
    }
    cout << endl;
}

// Tính diện tích đa giác
float DaGiac::DienTich() const {
    float area = 0;

    // Công thức Gauss để tính diện tích
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n; // Xử lý vòng lại đỉnh đầu
        area += dinh[i].getHoanh() * dinh[j].getTung() -
                dinh[j].getHoanh() * dinh[i].getTung();
    }
    return fabs(area) / 2.0;
}
