#include <iostream>
#include <vector>
#include "nhanvien.h"
using namespace std;

// Hàm nhập danh sách nhân viên
void nhapDanhSach(vector<NhanVien*>& danhSach) {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int loai;
        cout << "Nhap loai nhan vien (1-Lap Trinh Vien, 2-Kiem Chung Vien): ";
        cin >> loai;
        cin.ignore();

        string maNV, hoTen, soDienThoai, email;
        int tuoi;
        double luongCoBan;

        cout << "Ma NV: "; getline(cin, maNV);
        cout << "Ho Ten: "; getline(cin, hoTen);
        cout << "Tuoi: "; cin >> tuoi;
        cin.ignore();
        cout << "So Dien Thoai: "; getline(cin, soDienThoai);
        cout << "Email: "; getline(cin, email);
        cout << "Luong Co Ban: "; cin >> luongCoBan;

        if (loai == 1) {
            int soGioOvertime;
            cout << "So Gio Overtime: "; cin >> soGioOvertime;
            danhSach.push_back(new LapTrinhVien(maNV, hoTen, tuoi, soDienThoai, email, luongCoBan, soGioOvertime));
        } else if (loai == 2) {
            int soLoiPhatHien;
            cout << "So Loi Phat Hien: "; cin >> soLoiPhatHien;
            danhSach.push_back(new KiemChungVien(maNV, hoTen, tuoi, soDienThoai, email, luongCoBan, soLoiPhatHien));
        }
    }
}

// Hàm xuất danh sách nhân viên
void xuatDanhSach(const vector<NhanVien*>& danhSach) {
    for (const auto& nv : danhSach) {
        nv->xuatThongTin();
    }
}

// Hàm liệt kê nhân viên có lương thấp hơn mức trung bình
void lietKeLuongThapHonTB(const vector<NhanVien*>& danhSach) {
    double tongLuong = 0;
    for (const auto& nv : danhSach) {
        tongLuong += nv->tinhLuong();
    }
    double luongTB = tongLuong / danhSach.size();

    cout << "Danh sach nhan vien co luong thap hon trung binh (" << luongTB << "):" << endl;
    for (const auto& nv : danhSach) {
        if (nv->tinhLuong() < luongTB) {
            nv->xuatThongTin();
        }
    }
}

int main() {
    vector<NhanVien*> danhSach;

    nhapDanhSach(danhSach);
    cout << "\nDanh sach nhan vien:" << endl;
    xuatDanhSach(danhSach);

    cout << "\nNhan vien co luong thap hon muc luong trung binh:" << endl;
    lietKeLuongThapHonTB(danhSach);

    // Giải phóng bộ nhớ
    for (auto nv : danhSach) {
        delete nv;
    }

    return 0;
}
