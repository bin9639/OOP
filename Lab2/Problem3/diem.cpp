#include <iostream>
#include "Diem.h"
using namespace std;

Diem::Diem() : iHoanh(0), iTung(0) {}
Diem::Diem(int Hoanh, int Tung) : iHoanh(Hoanh), iTung(Tung) {}

int Diem::GetHoanhDo() const { return iHoanh; }
int Diem::GetTungDo() const { return iTung; }
void Diem::SetHoanhDo(int Hoanh) { iHoanh = Hoanh; }
void Diem::SetTungDo(int Tung) { iTung = Tung; }

void Diem::Xuat() const {
    cout << "(" << iHoanh << ", " << iTung << ")";
}

void Diem::TinhTien(int dx, int dy) {
    iHoanh += dx;
    iTung += dy;
}

