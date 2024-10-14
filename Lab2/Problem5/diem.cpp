#include "Diem.h"

// Constructor
Diem::Diem(int Hoanh, int Tung) : iHoanh(Hoanh), iTung(Tung) {}

// Xuất thông tin điểm dưới dạng (a, b)
void Diem::Xuat() const {
    cout << "(" << iHoanh << ", " << iTung << ")" << endl;
}

// Nhân đôi hoành độ và tung độ
void Diem::NhanDoi() {
    iHoanh *= 2;
    iTung *= 2;
}

// Gán điểm về gốc tọa độ (0, 0)
void Diem::GanGocToaDo() {
    iHoanh = 0;
    iTung = 0;
}

// Tịnh tiến điểm theo hướng k với độ tịnh tiến d
void Diem::TinhTien(int k, int d) {
    if (k == 0) {
        iHoanh += d; // Tịnh tiến theo trục x
    } else {
        iTung += d;  // Tịnh tiến theo trục y
    }
}

