// ngaythangnam.cpp
#include "ngaythangnam.h"

bool NgayThangNam::NamNhuan(int nam) const {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int NgayThangNam::SoNgayTrongThang(int thang, int nam) const {
    switch (thang) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return NamNhuan(nam) ? 29 : 28;
        default: return 31;
    }
}

NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {}

NgayThangNam::NgayThangNam(int nam, int thang, int ngay) : iNgay(ngay), iThang(thang), iNam(nam) {}

int NgayThangNam::TinhNgay() const {
    int totalDays = iNgay;
    for (int y = 0; y < iNam; ++y) {
        totalDays += NamNhuan(y) ? 366 : 365;
    }
    for (int m = 1; m < iThang; ++m) {
        totalDays += SoNgayTrongThang(m, iNam);
    }
    return totalDays;
}

void NgayThangNam::TinhLaiNgay(int totalDays) {
    iNam = 0;
    while (totalDays >= (NamNhuan(iNam) ? 366 : 365)) {
        totalDays -= NamNhuan(iNam) ? 366 : 365;
        iNam++;
    }

    iThang = 1;
    while (totalDays > SoNgayTrongThang(iThang, iNam)) {
        totalDays -= SoNgayTrongThang(iThang, iNam);
        iThang++;
    }

    iNgay = totalDays;
}

NgayThangNam NgayThangNam::operator+(int ngay) const {
    NgayThangNam result = *this;
    result.TinhLaiNgay(result.TinhNgay() + ngay);
    return result;
}

NgayThangNam NgayThangNam::operator-(int ngay) const {
    NgayThangNam result = *this;
    result.TinhLaiNgay(result.TinhNgay() - ngay);
    return result;
}

int NgayThangNam::operator-(const NgayThangNam& a) const {
    return TinhNgay() - a.TinhNgay();
}

NgayThangNam& NgayThangNam::operator++() {
    *this = *this + 1;
    return *this;
}

NgayThangNam NgayThangNam::operator++(int) {
    NgayThangNam temp = *this;
    *this = *this + 1;
    return temp;
}

NgayThangNam& NgayThangNam::operator--() {
    *this = *this - 1;
    return *this;
}

NgayThangNam NgayThangNam::operator--(int) {
    NgayThangNam temp = *this;
    *this = *this - 1;
    return temp;
}

bool NgayThangNam::operator==(const NgayThangNam& other) const {
    return TinhNgay() == other.TinhNgay();
}

bool NgayThangNam::operator!=(const NgayThangNam& other) const {
    return !(*this == other);
}

bool NgayThangNam::operator<(const NgayThangNam& other) const {
    return TinhNgay() < other.TinhNgay();
}

bool NgayThangNam::operator>(const NgayThangNam& other) const {
    return TinhNgay() > other.TinhNgay();
}

bool NgayThangNam::operator<=(const NgayThangNam& other) const {
    return !(*this > other);
}

bool NgayThangNam::operator>=(const NgayThangNam& other) const {
    return !(*this < other);
}

istream& operator>>(istream& in, NgayThangNam& nt) {
    cout << "Nhap nam: ";
    in >> nt.iNam;
    cout << "Nhap thang: ";
    in >> nt.iThang;
    cout << "Nhap ngay: ";
    in >> nt.iNgay;
    return in;
}

ostream& operator<<(ostream& out, const NgayThangNam& nt) {
    out << nt.iNgay << "/" << nt.iThang << "/" << nt.iNam;
    return out;
}

