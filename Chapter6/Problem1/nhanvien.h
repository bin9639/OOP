#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

// Lớp cơ sở NhanVien
class NhanVien {
protected:
    string maNV, hoTen, soDienThoai, email;
    int tuoi;
    double luongCoBan;

public:
    NhanVien(string maNV, string hoTen, int tuoi, string soDienThoai, string email, double luongCoBan);
    virtual double tinhLuong() = 0; // phương thức ảo tính lương
    virtual void xuatThongTin();
    virtual ~NhanVien() {}
};

// Lớp LapTrinhVien kế thừa từ NhanVien
class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    LapTrinhVien(string maNV, string hoTen, int tuoi, string soDienThoai, string email, double luongCoBan, int soGioOvertime);
    double tinhLuong() override;
    void xuatThongTin() override;
};

// Lớp KiemChungVien kế thừa từ NhanVien
class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;

public:
    KiemChungVien(string maNV, string hoTen, int tuoi, string soDienThoai, string email, double luongCoBan, int soLoiPhatHien);
    double tinhLuong() override;
    void xuatThongTin() override;
};

#endif // NHANVIEN_H

