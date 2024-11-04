#ifndef DAGIAC_H
#define DAGIAC_H

#include "Diem.h"
#include <vector>
using namespace std;

class DaGiac {
private:
    int n;                // Số đỉnh
    vector<Diem> dinh;    // Danh sách các đỉnh

public:
    void Nhap();          // Nhập thông tin đa giác
    void Xuat() const;    // Xuất thông tin đa giác
    float DienTich() const; // Tính diện tích đa giác
};

#endif

