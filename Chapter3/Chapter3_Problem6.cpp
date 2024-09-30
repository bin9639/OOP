#include <iostream>
using namespace std;

class SoPhuc {
private:
    float thuc;  // Phan thuc
    float ao;    // Phan ao

public:
    // Constructor mac dinh
    SoPhuc() {
        thuc = 0;
        ao = 0;
    }

    // Constructor co tham so
    SoPhuc(float phanThuc, float phanAo) {
        thuc = phanThuc;
        ao = phanAo;
    }

    // Phuong thuc thay doi phan thuc
    void setThuc(float phanThuc) {
        thuc = phanThuc;
    }

    // Phuong thuc thay doi phan ao
    void setAo(float phanAo) {
        ao = phanAo;
    }

    // Phuong thuc lay gia tri phan thuc
    float getThuc() const {
        return thuc;
    }

    // Phuong thuc lay gia tri phan ao
    float getAo() const {
        return ao;
    }

    // Phuong thuc nhap so phuc
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    // Phuong thuc xuat so phuc
    void xuat() const {
        if (ao >= 0) {
            cout << thuc << " + " << ao << "i" << endl;
        } else {
            cout << thuc << " - " << -ao << "i" << endl;
        }
    }

    // Phuong thuc cong hai so phuc
    SoPhuc cong(const SoPhuc& sp) const {
        SoPhuc ketQua;
        ketQua.thuc = thuc + sp.thuc;
        ketQua.ao = ao + sp.ao;
        return ketQua;
    }
};

int main() {
    // Tao doi tuong so phuc sp1 va sp2
    SoPhuc sp1, sp2;

    // Nhap thong tin cho so phuc thu nhat
    cout << "Nhap so phuc thu nhat: " << endl;
    sp1.nhap();

    // Nhap thong tin cho so phuc thu hai
    cout << "Nhap so phuc thu hai: " << endl;
    sp2.nhap();

    // Xuat hai so phuc vua nhap
    cout << "So phuc thu nhat: ";
    sp1.xuat();
    cout << "So phuc thu hai: ";
    sp2.xuat();

    // Cong hai so phuc
    SoPhuc tong = sp1.cong(sp2);
    cout << "Tong hai so phuc: ";
    tong.xuat();

    return 0;
}
