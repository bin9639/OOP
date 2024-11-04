// TamGiac.h - Khai báo lớp TamGiac
#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

class TamGiac {
private:
    Diem A, B, C; // Ba đỉnh của tam giác

public:
    TamGiac(Diem a, Diem b, Diem c);

    // Phương thức xuất thông tin tam giác
    void Xuat() const;

    // Tịnh tiến tam giác theo góc và khoảng cách
    void TinhTien(float goc, float khoangCach);
};

#endif // TAMGIAC_H
