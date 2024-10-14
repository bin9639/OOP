#include <iostream>
#include "DaGiac.h"
using namespace std;

int main() {
    DaGiac dg;

    cout << "Nhap toa do cac dinh cua da giac:\n";
    dg.Nhap();

    cout << "\nToa do cac dinh cua da giac vua nhap:\n";
    dg.Xuat();

    cout << "\nTinh tien da giac theo vector (2, 3):\n";
    dg.TinhTien(2, 3);
    dg.Xuat();

    cout << "\nPhong to da giac theo ti le 2:\n";
    dg.PhongTo(2);
    dg.Xuat();

    cout << "\nThu nho da giac theo ti le 0.5:\n";
    dg.ThuNho(2);
    dg.Xuat();

    cout << "\nQuay da giac quanh goc toa do (0,0) mot goc 90 do:\n";
    dg.Quay(90);
    dg.Xuat();

    return 0;
}
