#include "Diem.h"
#include <cmath> // Thư viện toán học cho sin, cos

const float PI = 3.14;

Diem::Diem(float Hoanh, float Tung) : iHoanh(Hoanh), iTung(Tung) {}

void Diem::Xuat() const {
    cout << "(" << iHoanh << ", " << iTung << ")" << endl;
}

// Tịnh tiến điểm theo góc và khoảng cách
void Diem::TinhTien(float goc, float khoangCach) {
    // Đổi góc từ độ sang radian
    float radian = goc * PI / 180.0;

    // Tính hoành độ và tung độ mới sau khi tịnh tiến
    iHoanh += khoangCach * cos(radian);
    iTung += khoangCach * sin(radian);
}
