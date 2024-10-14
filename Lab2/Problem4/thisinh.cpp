#include <iostream>
#include "ThiSinh.h"
using namespace std;

void ThiSinh::Nhap() {
    cout << "Nhap ten: ";
    getline(cin, Ten);

    cout << "Nhap MSSV: ";
    getline(cin, MSSV);

    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> iNgay >> iThang >> iNam;

    cout << "Nhap diem Toan: ";
    cin >> fToan;
    cout << "Nhap diem Van: ";
    cin >> fVan;
    cout << "Nhap diem Anh: ";
    cin >> fAnh;

    cin.ignore(); // Xử lý bỏ ký tự xuống dòng thừa
}

void ThiSinh::Xuat() const {
    cout << "Ten: " << Ten << endl;
    cout << "MSSV: " << MSSV << endl;
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << endl;
    cout << "Diem Toan: " << fToan << ", Diem Van: " << fVan
         << ", Diem Anh: " << fAnh << endl;
}

float ThiSinh::Tong() const {
    return fToan + fVan + fAnh;
}

