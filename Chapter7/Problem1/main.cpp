#include <iostream>
#include <vector>
#include "nhanvien.h"
using namespace std;

// Hàm nhập thông tin nhân viên từ bàn phím
NhanVien* nhapThongTinNhanVien() {
    int loaiNhanVien;
    cout << "Chon loai nhan vien (1 - Van Phong, 2 - San Xuat, 3 - Quan Ly): ";
    cin >> loaiNhanVien;
    cin.ignore(); // Xóa ký tự xuống dòng khỏi bộ đệm

    string hoTen, ngaySinh;
    double luongCoBan;

    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
    cout << "Nhap luong co ban: ";
    cin >> luongCoBan;

    if (loaiNhanVien == 1) {
        int soNgayLamViec;
        double troCap;
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
        cout << "Nhap tro cap: ";
        cin >> troCap;
        return new NhanVienVanPhong(hoTen, ngaySinh, luongCoBan, soNgayLamViec, troCap);

    } else if (loaiNhanVien == 2) {
        int soSanPham;
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        return new NhanVienSanXuat(hoTen, ngaySinh, luongCoBan, soSanPham);

    } else if (loaiNhanVien == 3) {
        double heSoChucVu, thuong;
        cout << "Nhap he so chuc vu: ";
        cin >> heSoChucVu;
        cout << "Nhap thuong: ";
        cin >> thuong;
        return new NhanVienQuanLy(hoTen, ngaySinh, luongCoBan, heSoChucVu, thuong);

    } else {
        cout << "Loai nhan vien khong hop le!" << endl;
        return nullptr;
    }
}

// Hàm tính tổng lương của công ty
double tinhTongLuong(const vector<NhanVien*>& danhSach) {
    double tongLuong = 0;
    for (const auto& nv : danhSach) {
        tongLuong += nv->tinhLuong();
    }
    return tongLuong;
}

// Hàm tìm kiếm nhân viên theo họ tên
NhanVien* timKiemNhanVien(const vector<NhanVien*>& danhSach, const string& hoTen) {
    for (const auto& nv : danhSach) {
        if (nv->getHoTen() == hoTen) {
            return nv;
        }
    }
    return nullptr;
}

int main() {
    vector<NhanVien*> danhSachNhanVien;
    int soNhanVien;

    cout << "Nhap so luong nhan vien: ";
    cin >> soNhanVien;

    for (int i = 0; i < soNhanVien; ++i) {
        cout << "\nNhap thong tin cho nhan vien thu " << i + 1 << ":" << endl;
        NhanVien* nv = nhapThongTinNhanVien();
        if (nv) {
            danhSachNhanVien.push_back(nv);
        }
    }

    // Xuất thông tin nhân viên
    cout << "\nDanh sach nhan vien:" << endl;
    for (const auto& nv : danhSachNhanVien) {
        nv->xuatThongTin();
    }

    // Tính tổng lương của công ty
    cout << "\nTong luong cua cong ty: " << tinhTongLuong(danhSachNhanVien) << endl;

    // Tìm kiếm nhân viên theo họ tên
    string hoTenTimKiem;
    cout << "\nNhap ho ten nhan vien can tim: ";
    cin.ignore();
    getline(cin, hoTenTimKiem);

    NhanVien* nvTimThay = timKiemNhanVien(danhSachNhanVien, hoTenTimKiem);
    if (nvTimThay) {
        cout << "\nThong tin nhan vien tim thay:" << endl;
        nvTimThay->xuatThongTin();
    } else {
        cout << "Khong tim thay nhan vien." << endl;
    }

    // Giải phóng bộ nhớ
    for (auto nv : danhSachNhanVien) {
        delete nv;
    }

    return 0;
}
