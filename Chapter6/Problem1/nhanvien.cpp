#include "nhanvien.h"
#include <iostream>
using namespace std;

// Định nghĩa hàm khởi tạo cho NhanVien
NhanVien::NhanVien(string maNV, string hoTen, int tuoi, string soDienThoai, string email, double luongCoBan)
    : maNV(maNV), hoTen(hoTen), tuoi(tuoi), soDienThoai(soDienThoai), email(email), luongCoBan(luongCoBan) {}

void NhanVien::xuatThongTin() {
    cout << "Ma NV: " << maNV << ", Ho Ten: " << hoTen << ", Tuoi: " << tuoi
         << ", So Dien Thoai: " << soDienThoai << ", Email: " << email
         << ", Luong Co Ban: " << luongCoBan;
}

// Định nghĩa hàm cho LapTrinhVien
LapTrinhVien::LapTrinhVien(string maNV, string hoTen, int tuoi, string soDienThoai, string email, double luongCoBan, int soGioOvertime)
    : NhanVien(maNV, hoTen, tuoi, soDienThoai, email, luongCoBan), soGioOvertime(soGioOvertime) {}

double LapTrinhVien::tinhLuong() {
    return luongCoBan + soGioOvertime * 200000;
}

void LapTrinhVien::xuatThongTin() {
    NhanVien::xuatThongTin();
    cout << ", So Gio Overtime: " << soGioOvertime << ", Luong: " << tinhLuong() << endl;
}

// Định nghĩa hàm cho KiemChungVien
KiemChungVien::KiemChungVien(string maNV, string hoTen, int tuoi, string soDienThoai, string email, double luongCoBan, int soLoiPhatHien)
    : NhanVien(maNV, hoTen, tuoi, soDienThoai, email, luongCoBan), soLoiPhatHien(soLoiPhatHien) {}

double KiemChungVien::tinhLuong() {
    return luongCoBan + soLoiPhatHien * 50000;
}

void KiemChungVien::xuatThongTin() {
    NhanVien::xuatThongTin();
    cout << ", So Loi Phat Hien: " << soLoiPhatHien << ", Luong: " << tinhLuong() << endl;
}

