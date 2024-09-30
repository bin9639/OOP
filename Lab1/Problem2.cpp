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

    // Hàm so sánh phân số
    bool lonHon(PhanSo ps) {
        // So sánh bằng cách nhân chéo
        return tuSo * ps.mauSo > ps.tuSo * mauSo;
    }

    // Hàm xuất phân số
    void xuat() {
        if (mauSo == 1) {
            cout << tuSo << endl;
        } else {
            cout << tuSo << "/" << mauSo << endl;
        }
    }
};

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();

    cout << "Nhap phan so thu hai:\n";
    ps2.nhap();

    // Rút gọn các phân số
    ps1.rutGon();
    ps2.rutGon();

    // So sánh và xuất phân số lớn hơn
    cout << "Phan so lon nhat la: ";
    if(!ps1.lonHon(ps2) && !ps2.lonHon(ps1))
    {
        cout<<"Phan so bang nhau";
        return 0;
    }
    if (ps1.lonHon(ps2)) {
        ps1.xuat();
    } else {
        ps2.xuat();
    }

    return 0;
}
