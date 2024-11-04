// thoigian.cpp
#include "thoigian.h"

ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
    TinhLaiGio(iGio * 3600 + iPhut * 60 + iGiay);
}

int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay / 3600;
    Giay %= 3600;
    iPhut = Giay / 60;
    iGiay = Giay % 60;
}

ThoiGian ThoiGian::operator+(int Giay) const {
    ThoiGian result;
    result.TinhLaiGio(TinhGiay() + Giay);
    return result;
}

ThoiGian ThoiGian::operator-(int Giay) const {
    ThoiGian result;
    result.TinhLaiGio(TinhGiay() - Giay);
    return result;
}

ThoiGian ThoiGian::operator+(const ThoiGian& a) const {
    ThoiGian result;
    result.TinhLaiGio(TinhGiay() + a.TinhGiay());
    return result;
}

ThoiGian ThoiGian::operator-(const ThoiGian& a) const {
    ThoiGian result;
    result.TinhLaiGio(TinhGiay() - a.TinhGiay());
    return result;
}

ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    *this = *this + 1;
    return temp;
}

ThoiGian& ThoiGian::operator--() {
    *this = *this - 1;
    return *this;
}

ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    *this = *this - 1;
    return temp;
}

bool ThoiGian::operator==(const ThoiGian& other) const {
    return TinhGiay() == other.TinhGiay();
}

bool ThoiGian::operator!=(const ThoiGian& other) const {
    return !(*this == other);
}

bool ThoiGian::operator<(const ThoiGian& other) const {
    return TinhGiay() < other.TinhGiay();
}

bool ThoiGian::operator>(const ThoiGian& other) const {
    return TinhGiay() > other.TinhGiay();
}

bool ThoiGian::operator<=(const ThoiGian& other) const {
    return !(*this > other);
}

bool ThoiGian::operator>=(const ThoiGian& other) const {
    return !(*this < other);
}

istream& operator>>(istream& in, ThoiGian& tg) {
    cout << "Nhap gio: ";
    in >> tg.iGio;
    cout << "Nhap phut: ";
    in >> tg.iPhut;
    cout << "Nhap giay: ";
    in >> tg.iGiay;
    tg.TinhLaiGio(tg.TinhGiay());
    return in;
}

ostream& operator<<(ostream& out, const ThoiGian& tg) {
    out << tg.iGio << " gio " << tg.iPhut << " phut " << tg.iGiay << " giay";
    return out;
}
