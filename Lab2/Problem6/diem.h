// Diem.h - Khai báo lớp Diem
#ifndef DIEM_H
#define DIEM_H

#include <iostream>
using namespace std;

class Diem {
private:
    float iHoanh; // Hoành độ (x)
    float iTung;  // Tung độ (y)

public:
    Diem(float Hoanh = 0, float Tung = 0);

    // Phương thức xuất thông tin điểm
    void Xuat() const;

    // Tịnh tiến điểm theo góc và khoảng cách
    void TinhTien(float goc, float khoangCach);
};

#endif // DIEM_H
