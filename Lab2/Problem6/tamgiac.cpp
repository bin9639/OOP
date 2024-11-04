#include "TamGiac.h"

TamGiac::TamGiac(Diem a, Diem b, Diem c) : A(a), B(b), C(c) {}

void TamGiac::Xuat() const {
    cout << "Diem A: "; A.Xuat();
    cout << "Diem B: "; B.Xuat();
    cout << "Diem C: "; C.Xuat();
}

void TamGiac::TinhTien(float goc, float khoangCach) {
    A.TinhTien(goc, khoangCach);
    B.TinhTien(goc, khoangCach);
    C.TinhTien(goc, khoangCach);
}

