// Diem.h - Khai báo lớp Diem
#ifndef DIEM_H
#define DIEM_H

#include <iostream>
using namespace std;

class Diem {
private:
    int iHoanh; // Hoành độ (x)
    int iTung;  // Tung độ (y)

public:
    // Constructor không tham số và có tham số
    Diem(int Hoanh = 0, int Tung = 0);

    // Phương thức để in thông tin điểm
    void Xuat() const;

    // Chỉ thị 1: Nhân đôi hoành độ và tung độ
    void NhanDoi();

    // Chỉ thị 2: Gán về gốc tọa độ (0, 0)
    void GanGocToaDo();

    // Chỉ thị 3: Tịnh tiến điểm
    void TinhTien(int k, int d);
};

#endif // DIEM_H
