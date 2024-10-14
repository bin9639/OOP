#include <iostream>
#include "TamGiac.h"
using namespace std;

int main() {
    TamGiac tg;

    cout << "Nhap toa do cac dinh tam giac:\n";
    tg.Nhap();

    cout << "\nToa do tam giac vua nhap:\n";
    tg.Xuat();

    cout << "\nTinh tien tam giac theo vector (2, 3):\n";
    tg.TinhTien(2, 3);
    tg.Xuat();

    cout << "\nPhong to tam giac theo ti le 2:\n";
    tg.PhongTo(2);
    tg.Xuat();

    cout << "\nThu nho tam giac theo ti le 0.5:\n";
    tg.ThuNho(2);
    tg.Xuat();

    cout << "\nQuay tam giac quanh dinh A mot goc 90 do:\n";
    tg.Quay(90);
    tg.Xuat();

    return 0;
}
