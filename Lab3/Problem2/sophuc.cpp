// sophuc.cpp
#include "sophuc.h"

SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

SoPhuc::SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

SoPhuc SoPhuc::operator+(const SoPhuc& other) {
    return SoPhuc(dThuc + other.dThuc, dAo + other.dAo);
}

SoPhuc SoPhuc::operator-(const SoPhuc& other) {
    return SoPhuc(dThuc - other.dThuc, dAo - other.dAo);
}

SoPhuc SoPhuc::operator*(const SoPhuc& other) {
    return SoPhuc(dThuc * other.dThuc - dAo * other.dAo,
                  dThuc * other.dAo + dAo * other.dThuc);
}

SoPhuc SoPhuc::operator/(const SoPhuc& other) {
    double denominator = other.dThuc * other.dThuc + other.dAo * other.dAo;
    return SoPhuc((dThuc * other.dThuc + dAo * other.dAo) / denominator,
                  (dAo * other.dThuc - dThuc * other.dAo) / denominator);
}

bool SoPhuc::operator==(const SoPhuc& other) {
    return dThuc == other.dThuc && dAo == other.dAo;
}

bool SoPhuc::operator!=(const SoPhuc& other) {
    return !(*this == other);
}

istream& operator>>(istream& in, SoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    in >> sp.dThuc;
    cout << "Nhap phan ao: ";
    in >> sp.dAo;
    return in;
}

ostream& operator<<(ostream& out, const SoPhuc& sp) {
    if (sp.dAo >= 0) {
        out << sp.dThuc << " + " << sp.dAo << "i";
    } else {
        out << sp.dThuc << " - " << -sp.dAo << "i";
    }
    return out;
}

