// Diem.h - Khai báo lớp Diem
#ifndef DIEM_H // Kiểm tra tránh khai báo lại
#define DIEM_H

class Diem {
private:
    int iHoanh, iTung;

public:
    Diem(); // Constructor mặc định
    Diem(int Hoanh, int Tung); // Constructor tham số

    int GetHoanhDo() const;
    int GetTungDo() const;
    void SetHoanhDo(int Hoanh);
    void SetTungDo(int Tung);
    void Xuat() const;
    void TinhTien(int dx, int dy);
};

#endif // DIEM_H
