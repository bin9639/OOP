
// sophuc.h
#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc {
private:
    double dThuc;
    double dAo;

public:
    SoPhuc();
    SoPhuc(double thuc, double ao);

    // Các toán tử
    SoPhuc operator+(const SoPhuc& other);
    SoPhuc operator-(const SoPhuc& other);
    SoPhuc operator*(const SoPhuc& other);
    SoPhuc operator/(const SoPhuc& other);

    bool operator==(const SoPhuc& other);
    bool operator!=(const SoPhuc& other);

    // Toán tử nhập >>
    friend istream& operator>>(istream& in, SoPhuc& sp);
    // Toán tử xuất <<
    friend ostream& operator<<(ostream& out, const SoPhuc& sp);
};

#endif // SOPHUC_H

