#include <iostream>
#include <vector>
#include <numeric>  // std::gcd
#include<bits/stdc++.h>
using namespace std;

class PhanSo {
private:
    int tuso;
    int mauso;

    // Hàm rút gọn phân số
    void RutGon() {
        int gcd = std::__gcd(tuso, mauso);
        tuso /= gcd;
        mauso /= gcd;
        if (mauso < 0) {  // Đưa dấu âm về tử số
            tuso = -tuso;
            mauso = -mauso;
        }
    }

public:
    // 1. Constructor với tham số mặc định và sao chép
    PhanSo(int t = 0, int m = 1) : tuso(t), mauso(m) {
        RutGon();  // Rút gọn ngay khi khởi tạo
    }

    PhanSo(const PhanSo& p) : tuso(p.tuso), mauso(p.mauso) {}

    // 2. Getter và Setter
    int LayTu() { return tuso; }
    int LayMau() { return mauso; }
    void GanTu(int t) { tuso = t; }
    void GanMau(int m) { mauso = m; }

    // 3. Nhập và xuất phân số
    void Nhap() {
        cout << "Nhap tu so: ";
        cin >> tuso;
        cout << "Nhap mau so: ";
        cin >> mauso;
        if (mauso == 0) {
            cout << "Mau so phai khac 0! Gan mac dinh mau = 1.\n";
            mauso = 1;
        }
        RutGon();
    }

    void Xuat() {
        cout << tuso << "/" << mauso;
    }

    // 4. Toán tử > (so sánh phân số)
    bool operator>(PhanSo p) {
        return tuso * p.mauso > p.tuso * mauso;
    }

    // 5. Toán tử + (cộng hai phân số)
    PhanSo operator+(PhanSo p) {
        int tu = tuso * p.mauso + p.tuso * mauso;
        int mau = mauso * p.mauso;
        return PhanSo(tu, mau);
    }

    // 6. Toán tử - (trừ hai phân số)
    PhanSo operator-(PhanSo p) {
        int tu = tuso * p.mauso - p.tuso * mauso;
        int mau = mauso * p.mauso;
        return PhanSo(tu, mau);
    }

    bool operator>(const PhanSo& p) const {
    return tuso * p.mauso > p.tuso * mauso;
}

};

class DSPhanSo {
private:
    vector<PhanSo> danhSach;

public:
    // 1. Nhập danh sách phân số
    void NhapDanhSach() {
        int n;
        cout << "Nhap so luong phan so: ";
        cin >> n;
        danhSach.resize(n);

        for (int i = 0; i < n; ++i) {
            cout << "\nNhap phan so thu " << i + 1 << ":\n";
            danhSach[i].Nhap();
        }
    }

    // 2. Xuất danh sách phân số
    void XuatDanhSach() const {
        cout << "\nDanh sach cac phan so:\n";
        for (auto ps:danhSach) {
            ps.Xuat();
            cout << "  ";
        }
        cout << endl;
    }

    // 3. Tìm phân số có giá trị lớn nhất
    PhanSo TimPhanSoLonNhat() const {
        if (danhSach.empty()) {
            cout << "Danh sach rong!\n";
            return PhanSo();
        }

        PhanSo max = danhSach[0];
        for (const auto& ps : danhSach) {
            if (ps > max) {
                max = ps;
            }
        }
        return max;
    }

    // 4. Tính tổng các phân số trong danh sách
    PhanSo TinhTong() const {
        PhanSo tong;
        for (const auto& ps : danhSach) {
            tong = tong + ps;
        }
        return tong;
    }
};

int main() {
    DSPhanSo ds;

    // Nhập danh sách phân số
    ds.NhapDanhSach();

    // Xuất danh sách phân số
    ds.XuatDanhSach();

    // Tìm và in phân số có giá trị lớn nhất
    PhanSo max = ds.TimPhanSoLonNhat();
    cout << "Phan so co gia tri lon nhat: ";
    max.Xuat();
    cout << endl;

    // Tính và in tổng các phân số
    PhanSo tong = ds.TinhTong();
    cout << "Tong cac phan so: ";
    tong.Xuat();
    cout << endl;

    return 0;
}


