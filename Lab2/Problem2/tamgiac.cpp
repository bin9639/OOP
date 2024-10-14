#include <iostream>
#include <cmath>
#include "TamGiac.h"
using namespace std;

const long double M_PI = acos(-1);

void TamGiac::Nhap() {
    int x, y;
    cout << "Nhap toa do dinh A:\n";
    cout << "Hoanh do: "; cin >> x;
    cout << "Tung do: "; cin >> y;
    A = Diem(x, y);

    cout << "Nhap toa do dinh B:\n";
    cout << "Hoanh do: "; cin >> x;
    cout << "Tung do: "; cin >> y;
    B = Diem(x, y);

    cout << "Nhap toa do dinh C:\n";
    cout << "Hoanh do: "; cin >> x;
    cout << "Tung do: "; cin >> y;
    C = Diem(x, y);
}

void TamGiac::Xuat() const {
    cout << "Dinh A: "; A.Xuat(); cout << endl;
    cout << "Dinh B: "; B.Xuat(); cout << endl;
    cout << "Dinh C: "; C.Xuat(); cout << endl;
}

void TamGiac::TinhTien(int dx, int dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

void TamGiac::PhongTo(float k) {
    B.TinhTien((B.GetHoanhDo() - A.GetHoanhDo()) * (k - 1),
               (B.GetTungDo() - A.GetTungDo()) * (k - 1));
    C.TinhTien((C.GetHoanhDo() - A.GetHoanhDo()) * (k - 1),
               (C.GetTungDo() - A.GetTungDo()) * (k - 1));
}

void TamGiac::ThuNho(float k) {
    PhongTo(1.0 / k);
}

void TamGiac::Quay(float goc) {
    float rad = goc * M_PI / 180.0;

    auto quayDinh = [&](Diem &P) {
        int x = P.GetHoanhDo() - A.GetHoanhDo();
        int y = P.GetTungDo() - A.GetTungDo();
        int xMoi = x * cos(rad) - y * sin(rad);
        int yMoi = x * sin(rad) + y * cos(rad);
        P.SetHoanhDo(xMoi + A.GetHoanhDo());
        P.SetTungDo(yMoi + A.GetTungDo());
    };

    quayDinh(B);
    quayDinh(C);
}
