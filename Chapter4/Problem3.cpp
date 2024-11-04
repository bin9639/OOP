#include <iostream>
#include <cmath>  // Để sử dụng hàm pow()
#include <stdexcept>  // Để xử lý ngoại lệ
using namespace std;

class DonThuc {
private:
    double a;  // Hệ số (a)
    int b;     // Số mũ (b)

public:
    // 1. Tạo lập đơn thức với giá trị mặc định
    DonThuc(double a = 0, int b = 0) : a(a), b(b) {}

    // 2. Nhập hoặc thay đổi thông tin đơn thức
    void Nhap() {
        cout << "Nhap he so a: ";
        cin >> a;
        cout << "Nhap so mu b: ";
        cin >> b;
    }

    // Thay đổi hệ số và số mũ
    void ThayDoiThongTin(double newA, int newB) {
        a = newA;
        b = newB;
    }

    // 3. Xuất đơn thức ra màn hình
    void Xuat() const {
        if (a == 0) {
            cout << "0";  // Nếu hệ số bằng 0 thì đơn thức là 0
        } else if (b == 0) {
            cout << a;  // Nếu bậc 0, chỉ in hệ số
        } else if (b == 1) {
            cout << a << "x";  // Nếu bậc 1, in "ax"
        } else {
            cout << a << "x^" << b;  // Dạng tổng quát "ax^b"
        }
    }

    // 4. Tính giá trị của đơn thức khi biết x
    double TinhGiaTri(double x) const {
        return a * pow(x, b);
    }

    // 5. Tính đạo hàm của đơn thức (P'(x) = a * b * x^(b-1))
    DonThuc DaoHam() const {
        if (b == 0) return DonThuc(0, 0);  // Đạo hàm của hằng số là 0
        return DonThuc(a * b, b - 1);
    }

    // 6. Tính tổng hai đơn thức cùng bậc
    DonThuc Cong(const DonThuc& other) const {
        if (b != other.b) {
            throw invalid_argument("Hai don thuc phai cung bac de cong.");
        }
        return DonThuc(a + other.a, b);
    }
};

// 7. Chương trình chính để nhập và tính tổng hai đơn thức
int main() {
    DonThuc dt1, dt2;

    cout << "Nhap don thuc thu nhat:\n";
    dt1.Nhap();
    cout << "Nhap don thuc thu hai:\n";
    dt2.Nhap();

    try {
        cout << "Tong hai don thuc: ";
        DonThuc tong = dt1.Cong(dt2);
        tong.Xuat();
        cout << endl;
    } catch (const exception& e) {
        cout << "Loi: " << e.what() << endl;
    }

    cout << "Dao ham cua don thuc thu nhat: ";
    DonThuc daoHamDt1 = dt1.DaoHam();
    daoHamDt1.Xuat();
    cout << endl;

    double x;
    cout << "Nhap gia tri x de tinh P(x) cua don thuc thu nhat: ";
    cin >> x;
    cout << "P(" << x << ") = " << dt1.TinhGiaTri(x) << endl;

    return 0;
}
