// TamGiac.h - Khai báo lớp TamGiac
#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h" // Sử dụng lớp Diem

class TamGiac {
private:
    Diem A, B, C;

public:
    void Nhap();
    void Xuat() const;
    void TinhTien(int dx, int dy);
    void PhongTo(float k);
    void ThuNho(float k);
    void Quay(float goc);
};

#endif // TAMGIAC_H
