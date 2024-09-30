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
        
        // Kiểm tra phân số hợp lệ
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
        
        // Xử lý trường hợp mẫu âm
        if (mauSo < 0) {
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }
    
    // Hàm xuất phân số
    void xuat() {
        if (mauSo == 1) {
            cout << "Phan so sau khi rut gon: " << tuSo << endl;
        } else {
            cout << "Phan so sau khi rut gon: " << tuSo << "/" << mauSo << endl;
        }
    }
};

int main() {
    PhanSo ps;
    ps.nhap();
    ps.rutGon();
    ps.xuat();
    return 0;
}
