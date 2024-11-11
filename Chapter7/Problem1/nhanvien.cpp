#include "nhanvien.h"
#include <iostream>
using namespace std;

NhanVien::NhanVien(string hoTen, string ngaySinh, double luongCoBan)
    : hoTen(hoTen), ngaySinh(ngaySinh), luongCoBan(luongCoBan) {}

void NhanVien::xuatThongTin() const {
    cout << "Ho Ten: " << hoTen << ", Ngay Sinh: " << ngaySinh << ", Luong Co Ban: " << luongCoBan;
}

// NhanVienVanPhong
NhanVienVanPhong::NhanVienVanPhong(string hoTen, string ngaySinh, double luongCoBan, int soNgayLamViec, double troCap)
    : NhanVien(hoTen, ngaySinh, luongCoBan), soNgayLamViec(soNgayLamViec), troCap(troCap) {}

double NhanVienVanPhong::tinhLuong() const {
    return luongCoBan + soNgayLamViec * 200000 + troCap;
}

void NhanVienVanPhong::xuatThongTin() const {
    NhanVien::xuatThongTin();
    cout << ", So Ngay Lam Viec: " << soNgayLamViec << ", Tro Cap: " << troCap << ", Luong: " << tinhLuong() << endl;
}

// NhanVienSanXuat
NhanVienSanXuat::NhanVienSanXuat(string hoTen, string ngaySinh, double luongCoBan, int soSanPham)
    : NhanVien(hoTen, ngaySinh, luongCoBan), soSanPham(soSanPham) {}

double NhanVienSanXuat::tinhLuong() const{
    return luongCoBan + soSanPham * 2000;
}

void NhanVienSanXuat::xuatThongTin() const {
    NhanVien::xuatThongTin();
    cout << ", So San Pham: " << soSanPham << ", Luong: " << tinhLuong() << endl;
}

// NhanVienQuanLy
NhanVienQuanLy::NhanVienQuanLy(string hoTen, string ngaySinh, double luongCoBan, double heSoChucVu, double thuong)
    : NhanVien(hoTen, ngaySinh, luongCoBan), heSoChucVu(heSoChucVu), thuong(thuong) {}

double NhanVienQuanLy::tinhLuong() const{
    return luongCoBan * heSoChucVu + thuong;
}

void NhanVienQuanLy::xuatThongTin() const {
    NhanVien::xuatThongTin();
    cout << ", He So Chuc Vu: " << heSoChucVu << ", Thuong: " << thuong << ", Luong: " << tinhLuong() << endl;
}

