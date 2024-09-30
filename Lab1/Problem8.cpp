#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;

class SavingAccount {
private:
    string maSo;
    string loaiTietKiem;
    string hoTenKhachHang;
    string cmnd;
    string ngayMoSo;
    double soTienGui;
    double laiSuat;

public:
    // Hàm khởi tạo
    SavingAccount() : soTienGui(0), laiSuat(0) {}

    // Hàm nhập thông tin sổ tiết kiệm
    void nhapThongTin() {
        do {
            cout << "Nhap ma so (toi da 5 ky tu, khong khoang trang hoac ky tu dac biet): ";
            cin >> maSo;
        } while (maSo.length() > 5 || maSo.find(' ') != string::npos);

        do {
            cout << "Nhap loai tiet kiem (toi da 10 ky tu): ";
            cin >> loaiTietKiem;
        } while (loaiTietKiem.length() > 10);

        do {
            cout << "Nhap ho ten khach hang (toi da 30 ky tu, khong ky tu dac biet): ";
            cin.ignore();
            getline(cin, hoTenKhachHang);
        } while (hoTenKhachHang.length() > 30 || !kiemTraChuoiHopLe(hoTenKhachHang));

        do {
            cout << "Nhap CMND (9 hoac 12 chu so): ";
            cin >> cmnd;
        } while (cmnd.length() != 9 && cmnd.length() != 12);

        do {
            cout << "Nhap ngay mo so (dd/mm/yyyy): ";
            cin >> ngayMoSo;
        } while (!kiemTraNgayHopLe(ngayMoSo));

        do {
            cout << "Nhap so tien gui (duong): ";
            cin >> soTienGui;
        } while (soTienGui <= 0);
    }

    // Hàm kiểm tra chuỗi có hợp lệ không (không chứa ký tự đặc biệt)
    bool kiemTraChuoiHopLe(const string &s) {
        for (char c : s) {
            if (!isalnum(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    // Hàm kiểm tra ngày hợp lệ
    bool kiemTraNgayHopLe(const string &ngay) {
        if (ngay.length() != 10 || ngay[2] != '/' || ngay[5] != '/') return false;
        int day = stoi(ngay.substr(0, 2));
        int month = stoi(ngay.substr(3, 2));
        int year = stoi(ngay.substr(6, 4));
        if (month < 1 || month > 12 || day < 1 || day > 31) return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
        if (month == 2) {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (isLeap && day > 29) return false;
            if (!isLeap && day > 28) return false;
        }
        return true;
    }

    // Hàm xuất thông tin sổ tiết kiệm
    void xuatThongTin() const {
        cout << "Ma so: " << maSo << ", Loai tiet kiem: " << loaiTietKiem
             << ", Ho ten khach hang: " << hoTenKhachHang
             << ", CMND: " << cmnd << ", Ngay mo so: " << ngayMoSo
             << ", So tien gui: " << soTienGui << endl;
    }

    // Hàm cập nhật lãi suất
    void capNhatLaiSuat(double ls) {
        laiSuat = ls;
    }

    // Hàm tính lãi
    double tinhLai() const {
        return soTienGui * (laiSuat / 100.0);
    }

    // Lấy ngày mở sổ
    string getNgayMoSo() const {
        return ngayMoSo;
    }

    // Lấy số tiền gửi
    double getSoTienGui() const {
        return soTienGui;
    }

    // Lấy mã số để tìm kiếm
    string getMaSo() const {
        return maSo;
    }

    // Lấy CMND để tìm kiếm
    string getCMND() const {
        return cmnd;
    }
};

// Hàm so sánh theo số tiền gửi giảm dần
bool soSanhTheoTienGui(const SavingAccount &a, const SavingAccount &b) {
    return a.getSoTienGui() > b.getSoTienGui();
}

// Hàm so sánh theo ngày mở sổ tăng dần
bool soSanhTheoNgayMoSo(const SavingAccount &a, const SavingAccount &b) {
    return a.getNgayMoSo() < b.getNgayMoSo();
}

int main() {
    vector<SavingAccount> danhSach;
    int soLuong;

    cout << "Nhap so luong so tiet kiem: ";
    cin >> soLuong;

    // Nhập thông tin
    for (int i = 0; i < soLuong; i++) {
        SavingAccount account;
        cout << "Nhap thong tin so tiet kiem thu " << i + 1 << ": " << endl;
        account.nhapThongTin();
        danhSach.push_back(account);
    }

    // Sắp xếp theo số tiền gửi giảm dần
    sort(danhSach.begin(), danhSach.end(), soSanhTheoTienGui);
    cout << "\nDanh sach sap xep theo so tien gui (giam dan):\n";
    for (const auto &acc : danhSach) {
        acc.xuatThongTin();
    }

    // Sắp xếp theo ngày mở sổ tăng dần
    sort(danhSach.begin(), danhSach.end(), soSanhTheoNgayMoSo);
    cout << "\nDanh sach sap xep theo ngay mo so (tang dan):\n";
    for (const auto &acc : danhSach) {
        acc.xuatThongTin();
    }

    return 0;
}
