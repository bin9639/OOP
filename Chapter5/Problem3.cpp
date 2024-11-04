

#include <iostream>
#include <vector>
#include <cmath>  // std::pow
#include <string> // std::to_string
using namespace std;

class DaThuc {
private:
    vector<double> heSo;

public:
    DaThuc() : heSo(1, 0.0) {}
    DaThuc(int bac) : heSo(bac + 1, 0.0) {}

    friend istream& operator>>(istream& is, DaThuc& dt) {
        cout << "Nhap bac cua da thuc: ";
        int bac;
        is >> bac;
        dt.heSo.resize(bac + 1);

        for (int i = bac; i >= 0; --i) {
            cout << "Nhap he so a" << i << ": ";
            is >> dt.heSo[i];
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const DaThuc& dt) {
        bool first = true;
        for (int i = dt.heSo.size() - 1; i >= 0; --i) {
            if (dt.heSo[i] != 0) {
                if (!first && dt.heSo[i] > 0) os << " + ";
                if (dt.heSo[i] < 0) os << " - ";

                // Sửa lỗi bằng cách chuyển giá trị thành chuỗi
                if (abs(dt.heSo[i]) != 1 || i == 0)
                    os << abs(dt.heSo[i]);

                if (i > 0) os << "x";
                if (i > 1) os << "^" << i;

                first = false;
            }
        }
        if (first) os << "0";
        return os;
    }

    double TinhGiaTri(double x) const {
        double ketQua = 0;
        for (int i = 0; i < heSo.size(); ++i) {
            ketQua += heSo[i] * pow(x, i);
        }
        return ketQua;
    }

    DaThuc operator+(const DaThuc& dt) const {
        int bacMax = max(heSo.size(), dt.heSo.size());
        DaThuc ketQua(bacMax - 1);

        for (int i = 0; i < bacMax; ++i) {
            double a = (i < heSo.size()) ? heSo[i] : 0;
            double b = (i < dt.heSo.size()) ? dt.heSo[i] : 0;
            ketQua.heSo[i] = a + b;
        }
        return ketQua;
    }

    DaThuc operator-(const DaThuc& dt) const {
        int bacMax = max(heSo.size(), dt.heSo.size());
        DaThuc ketQua(bacMax - 1);

        for (int i = 0; i < bacMax; ++i) {
            double a = (i < heSo.size()) ? heSo[i] : 0;
            double b = (i < dt.heSo.size()) ? dt.heSo[i] : 0;
            ketQua.heSo[i] = a - b;
        }
        return ketQua;
    }
};


int main() {
    DaThuc dt1, dt2;

    cout << "Nhap da thuc thu nhat:\n";
    cin >> dt1;
    cout << "Nhap da thuc thu hai:\n";
    cin >> dt2;

    cout << "\nDa thuc thu nhat: " << dt1 << endl;
    cout << "Da thuc thu hai: " << dt2 << endl;

    DaThuc tong = dt1 + dt2;
    DaThuc hieu = dt1 - dt2;

    cout << "\nTong hai da thuc: " << tong << endl;
    cout << "Hieu hai da thuc: " << hieu << endl;

    double x;
    cout << "\nNhap gia tri cua x: ";
    cin >> x;

    cout << "Gia tri da thuc thu nhat tai x = " << x << " la: " << dt1.TinhGiaTri(x) << endl;
    cout << "Gia tri da thuc thu hai tai x = " << x << " la: " << dt2.TinhGiaTri(x) << endl;

    return 0;
}
