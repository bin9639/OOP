// phanso.h
#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int Tu;
    int Mau;

public:
    PhanSo();
    PhanSo(int tu, int mau);

    // Phương thức tối giản phân số
    void simplify();

    // Các toán tử
    PhanSo operator+(const PhanSo& other);
    PhanSo operator-(const PhanSo& other);
    PhanSo operator*(const PhanSo& other);
    PhanSo operator/(const PhanSo& other);

    bool operator==(const PhanSo& other);
    bool operator!=(const PhanSo& other);
    bool operator<(const PhanSo& other);
    bool operator>(const PhanSo& other);
    bool operator<=(const PhanSo& other);
    bool operator>=(const PhanSo& other);

    // Toán tử nhập >>
    friend istream& operator>>(istream& in, PhanSo& ps);
    // Toán tử xuất <<
    friend ostream& operator<<(ostream& out, const PhanSo& ps);
};

#endif // PHANSO_H
