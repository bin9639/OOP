// phanso.cpp
#include "phanso.h"
#include <algorithm> // Để sử dụng hàm std::gcd

PhanSo::PhanSo() : Tu(0), Mau(1) {}

PhanSo::PhanSo(int tu, int mau) {
    Tu = tu;
    Mau = mau != 0 ? mau : 1; // Kiểm tra để mẫu số khác 0
    simplify();
}

void PhanSo::simplify() {
    int gcd = std::__gcd(abs(Tu), abs(Mau));
    Tu /= gcd;
    Mau /= gcd;
    if (Mau < 0) { // Đảm bảo mẫu số luôn dương
        Tu = -Tu;
        Mau = -Mau;
    }
}

PhanSo PhanSo::operator+(const PhanSo& other) {
    PhanSo result(Tu * other.Mau + other.Tu * Mau, Mau * other.Mau);
    result.simplify();
    return result;
}

PhanSo PhanSo::operator-(const PhanSo& other) {
    PhanSo result(Tu * other.Mau - other.Tu * Mau, Mau * other.Mau);
    result.simplify();
    return result;
}

PhanSo PhanSo::operator*(const PhanSo& other) {
    PhanSo result(Tu * other.Tu, Mau * other.Mau);
    result.simplify();
    return result;
}

PhanSo PhanSo::operator/(const PhanSo& other) {
    PhanSo result(Tu * other.Mau, Mau * other.Tu);
    result.simplify();
    return result;
}

bool PhanSo::operator==(const PhanSo& other) {
    return Tu * other.Mau == Mau * other.Tu;
}

bool PhanSo::operator!=(const PhanSo& other) {
    return !(*this == other);
}

bool PhanSo::operator<(const PhanSo& other) {
    return Tu * other.Mau < Mau * other.Tu;
}

bool PhanSo::operator>(const PhanSo& other) {
    return Tu * other.Mau > Mau * other.Tu;
}

bool PhanSo::operator<=(const PhanSo& other) {
    return !(*this > other);
}

bool PhanSo::operator>=(const PhanSo& other) {
    return !(*this < other);
}

istream& operator>>(istream& in, PhanSo& ps) {
    cout << "Nhap tu so: ";
    in >> ps.Tu;
    cout << "Nhap mau so: ";
    in >> ps.Mau;
    if (ps.Mau == 0) {
        ps.Mau = 1;
        cout << "Mau so khong the bang 0, tu dong chuyen ve 1.\n";
    }
    ps.simplify();
    return in;
}

ostream& operator<<(ostream& out, const PhanSo& ps) {
    if (ps.Mau == 1) {
        out << ps.Tu;
    } else {
        out << ps.Tu << "/" << ps.Mau;
    }
    return out;
}
