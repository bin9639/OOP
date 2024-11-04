#ifndef DIEM_H
#define DIEM_H

#include <iostream>
using namespace std;

class Diem {
private:
    float hoanh, tung;

public:
    Diem(float h = 0, float t = 0); // Constructor
    void Nhap();                    // Nhập tọa độ
    void Xuat() const;              // Xuất tọa độ
    float getHoanh() const;         // Lấy hoành độ
    float getTung() const;          // Lấy tung độ
};

#endif
