#include "Diem.h"

// Constructor
Diem::Diem(float h, float t) : hoanh(h), tung(t) {}

// Nhập tọa độ
void Diem::Nhap() {
    cout << "Nhap hoanh do va tung do: ";
    cin >> hoanh >> tung;
}

// Xuất tọa độ
void Diem::Xuat() const {
    cout << "(" << hoanh << ", " << tung << ")";
}

// Lấy hoành độ
float Diem::getHoanh() const {
    return hoanh;
}

// Lấy tung độ
float Diem::getTung() const {
    return tung;
}
