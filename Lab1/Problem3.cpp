#include <iostream>
using namespace std;

// Lớp Phân số
class PhanSo {
private:
    int tuSo, mauSo;

    // Hàm tìm UCLN của hai số
    int UCLN(int a, int b) {
        if (b == 0) return a;
        return UCLN(b, a % b);
    }

public:
    // Hàm khởi tạo
    PhanSo(int tu = 0, int mau = 1) : tuSo(tu), mauSo(mau) {}

    // Hàm nhập phân số
    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        cout << "Nhap mau so: ";
        cin >> mauSo;
        while (mauSo == 0) {
            cout << "Loi: Mau so phai khac 0. Nhap lai mau so: ";
            cin >> mauSo;
        }
    }

    // Hàm rút gọn phân số
    void rutGon() {
        int ucln = UCLN(abs(tuSo), abs(mauSo));
        tuSo /= ucln;
        mauSo /= ucln;
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Hàm xuất phân số
    void xuat() {
        if (mauSo == 1) {
            cout << tuSo << endl;
        } else {
            cout << tuSo << "/" << mauSo << endl;
        }
    }

    // Hàm tính tổng hai phân số
    PhanSo cong(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.mauSo + ps.tuSo * mauSo;
        kq.mauSo = mauSo * ps.mauSo;
        kq.rutGon();
        return kq;
    }

    // Hàm tính hiệu hai phân số
    PhanSo tru(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.mauSo - ps.tuSo * mauSo;
        kq.mauSo = mauSo * ps.mauSo;
        kq.rutGon();
        return kq;
    }

    // Hàm tính tích hai phân số
    PhanSo nhan(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.tuSo;
        kq.mauSo = mauSo * ps.mauSo;
        kq.rutGon();
        return kq;
    }

    // Hàm tính thương hai phân số
    PhanSo chia(PhanSo ps) {
        PhanSo kq;
        kq.tuSo = tuSo * ps.mauSo;
        kq.mauSo = mauSo * ps.tuSo;
        kq.rutGon();
        return kq;
    }


    //kiểm tra bằng 0 không

    bool zero()
    {
        return tuSo == 0;
    }
};

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();

    cout << "Nhap phan so thu hai:\n";
    ps2.nhap();

    // Tính và xuất tổng
    PhanSo tong = ps1.cong(ps2);
    cout << "Tong hai phan so: ";
    tong.xuat();

    // Tính và xuất hiệu
    PhanSo hieu = ps1.tru(ps2);
    cout << "Hieu hai phan so: ";
    hieu.xuat();

    // Tính và xuất tích
    PhanSo tich = ps1.nhan(ps2);
    cout << "Tich hai phan so: ";
    tich.xuat();

    // Tính và xuất thương
    PhanSo thuong = ps1.chia(ps2);
    if(ps2.zero())
        cout<<"Khong the tinh thuong vi phan so thu hai bang 0";
            else cout << "Thuong hai phan so: ", thuong.xuat();

    return 0;
}
