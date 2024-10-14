// ThiSinh.h - Khai báo lớp ThiSinh
#ifndef THISINH_H
#define THISINH_H

#include <string>
using namespace std;

class ThiSinh {
private:
    string Ten;
    string MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;

public:
    void Nhap();       // Nhập thông tin thí sinh
    void Xuat() const; // Xuất thông tin thí sinh
    float Tong() const; // Tính tổng điểm
};

#endif // THISINH_H
