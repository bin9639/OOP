#include <iostream>
#include <cmath>
#include "DaGiac.h"
using namespace std;

const long double M_PI = acos(-1);

// Constructor mặc định
DaGiac::DaGiac() : n(0), Dinh(nullptr) {}

// Constructor với số đỉnh
DaGiac::DaGiac(int soDinh) : n(soDinh) {
    Dinh = new Diem[n];
}

// Destructor để giải phóng bộ nhớ
DaGiac::~DaGiac() {
    delete[] Dinh;
}

// Nhập tọa độ các đỉnh
void DaGiac::Nhap() {
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;
    Dinh = new Diem[n];  // Cấp phát bộ nhớ cho các đỉnh

    for (int i = 0; i < n; ++i) {
        int x, y;
        cout << "Nhap toa do dinh " << i + 1 << ":\n";
        cout << "Hoanh do: "; cin >> x;
        cout << "Tung do: "; cin >> y;
        Dinh[i] = Diem(x, y);
    }
}

// Xuất tọa độ các đỉnh
void DaGiac::Xuat() const {
    cout << "Toa do cac dinh cua da giac:\n";
    for (int i = 0; i < n; ++i) {
        Dinh[i].Xuat();
        cout << endl;
    }
}

// Tịnh tiến đa giác theo vector (dx, dy)
void DaGiac::TinhTien(int dx, int dy) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].TinhTien(dx, dy);
    }
}

// Phóng to đa giác theo tỉ lệ k
void DaGiac::PhongTo(float k) {
    for (int i = 0; i < n; ++i) {
        Dinh[i].SetHoanhDo(Dinh[i].GetHoanhDo() * k);
        Dinh[i].SetTungDo(Dinh[i].GetTungDo() * k);
    }
}

// Thu nhỏ đa giác theo tỉ lệ k
void DaGiac::ThuNho(float k) {
    PhongTo(1.0 / k);
}

// Quay đa giác quanh gốc tọa độ (0,0) một góc goc (độ)
void DaGiac::Quay(float goc) {
    float rad = goc * M_PI / 180.0;  // Chuyển đổi độ sang radian

    for (int i = 0; i < n; ++i) {
        int x = Dinh[i].GetHoanhDo();
        int y = Dinh[i].GetTungDo();

        int xMoi = x * cos(rad) - y * sin(rad);
        int yMoi = x * sin(rad) + y * cos(rad);

        Dinh[i].SetHoanhDo(xMoi);
        Dinh[i].SetTungDo(yMoi);
    }
}
