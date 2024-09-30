#include <iostream>
#include <string>
using namespace std;

class cHocSinh {
private:
    string maHS;           // Ma hoc sinh
    string hoTen;          // Ho va ten
    string gioiTinh;       // Gioi tinh
    int namSinh;           // Nam sinh
    float diemTrungBinh;   // Diem trung binh

public:
    // Constructor mac dinh
    cHocSinh() {}

    // Constructor co tham so
    cHocSinh(string ma, string ten, string gioi, int nam, float diem) {
        maHS = ma;
        hoTen = ten;
        gioiTinh = gioi;
        namSinh = nam;
        diemTrungBinh = diem;
    }

    // Phuong thuc nhap thong tin hoc sinh
    void nhapThongTin() {
        cout << "Nhap ma hoc sinh: ";
        getline(cin, maHS);
        cout << "Nhap ho ten hoc sinh: ";
        getline(cin, hoTen);
        cout << "Nhap gioi tinh hoc sinh: ";
        getline(cin, gioiTinh);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap diem trung binh: ";
        cin >> diemTrungBinh;
        cin.ignore();  // Xoa bo nho dem sau khi nhap so
    }

    // Phuong thuc xuat thong tin hoc sinh
    void xuatThongTin() {
        cout << "Ma hoc sinh: " << maHS << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "Nam sinh: " << namSinh << endl;
        cout << "Diem trung binh: " << diemTrungBinh << endl;
    }

    // Getter cho diem trung binh
    float getDiemTrungBinh() {
        return diemTrungBinh;
    }

    // Getter cho nam sinh
    int getNamSinh() {
        return namSinh;
    }
};

int main() {
    // Tao 2 doi tuong hoc sinh
    cHocSinh hs1, hs2;

    // Nhap thong tin hoc sinh thu nhat
    cout << "Nhap thong tin hoc sinh thu nhat: " << endl;
    hs1.nhapThongTin();

    // Nhap thong tin hoc sinh thu hai
    cout << "Nhap thong tin hoc sinh thu hai: " << endl;
    hs2.nhapThongTin();

    // So sanh diem trung binh
    if (hs1.getDiemTrungBinh() > hs2.getDiemTrungBinh()) {
        cout << "Hoc sinh thu nhat co diem trung binh cao hon." << endl;
    } else if (hs1.getDiemTrungBinh() < hs2.getDiemTrungBinh()) {
        cout << "Hoc sinh thu hai co diem trung binh cao hon." << endl;
    } else {
        cout << "Hai hoc sinh co diem trung binh bang nhau." << endl;
    }

    // So sanh tuoi (nam sinh)
    if (hs1.getNamSinh() > hs2.getNamSinh()) {
        cout << "Hoc sinh thu nhat tre hon." << endl;
    } else if (hs1.getNamSinh() < hs2.getNamSinh()) {
        cout << "Hoc sinh thu hai tre hon." << endl;
    } else {
        cout << "Hai hoc sinh co cung tuoi." << endl;
    }

    return 0;
}
