#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
using namespace std;

// Lớp cơ sở NhanVien
class NhanVien {
protected:
    string hoTen, ngaySinh;
    double luongCoBan;

public:
    NhanVien(string hoTen, string ngaySinh, double luongCoBan);
    virtual double tinhLuong() const = 0;
    virtual void xuatThongTin() const;
    string getHoTen() const { return hoTen; }
    virtual ~NhanVien() {}
};

// Lớp NhanVienVanPhong kế thừa từ NhanVien
class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
    double troCap;

public:
    NhanVienVanPhong(string hoTen, string ngaySinh, double luongCoBan, int soNgayLamViec, double troCap);
    double tinhLuong() const override;
    void xuatThongTin() const override;
};

// Lớp NhanVienSanXuat kế thừa từ NhanVien
class NhanVienSanXuat : public NhanVien {
private:
    int soSanPham;

public:
    NhanVienSanXuat(string hoTen, string ngaySinh, double luongCoBan, int soSanPham);
    double tinhLuong() const override;
    void xuatThongTin() const override;
};

// Lớp NhanVienQuanLy kế thừa từ NhanVien
class NhanVienQuanLy : public NhanVien {
private:
    double heSoChucVu;
    double thuong;

public:
    NhanVienQuanLy(string hoTen, string ngaySinh, double luongCoBan, double heSoChucVu, double thuong);
    double tinhLuong() const override;
    void xuatThongTin() const override;
};

#endif // NHANVIEN_H

