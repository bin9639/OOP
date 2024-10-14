// DaGiac.h - Khai báo lớp DaGiac
#ifndef DAGIAC_H
#define DAGIAC_H

#include "Diem.h"  // Sử dụng lớp Diem đã xây dựng

class DaGiac {
private:
    int n;         // Số đỉnh của đa giác
    Diem *Dinh;    // Mảng các đỉnh của đa giác

public:
    DaGiac();                         // Constructor mặc định
    DaGiac(int soDinh);               // Constructor với số đỉnh
    ~DaGiac();                        // Destructor

    void Nhap();                      // Nhập tọa độ các đỉnh
    void Xuat() const;                // Xuất tọa độ các đỉnh
    void TinhTien(int dx, int dy);    // Tịnh tiến đa giác
    void PhongTo(float k);            // Phóng to đa giác
    void ThuNho(float k);             // Thu nhỏ đa giác
    void Quay(float goc);             // Quay đa giác quanh gốc tọa độ (0,0)
};

#endif // DAGIAC_H
