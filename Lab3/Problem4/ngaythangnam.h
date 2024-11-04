// ngaythangnam.h
#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

    bool NamNhuan(int nam) const;
    int SoNgayTrongThang(int thang, int nam) const;

public:
    NgayThangNam();
    NgayThangNam(int nam, int thang, int ngay);

    int TinhNgay() const;
    void TinhLaiNgay(int totalDays);

    NgayThangNam operator+(int ngay) const;
    NgayThangNam operator-(int ngay) const;
    int operator-(const NgayThangNam& a) const;

    NgayThangNam& operator++();
    NgayThangNam operator++(int);
    NgayThangNam& operator--();
    NgayThangNam operator--(int);

    bool operator==(const NgayThangNam& other) const;
    bool operator!=(const NgayThangNam& other) const;
    bool operator<(const NgayThangNam& other) const;
    bool operator>(const NgayThangNam& other) const;
    bool operator<=(const NgayThangNam& other) const;
    bool operator>=(const NgayThangNam& other) const;

    friend istream& operator>>(istream& in, NgayThangNam& nt);
    friend ostream& operator<<(ostream& out, const NgayThangNam& nt);
};

#endif // NGAYTHANGNAM_H

