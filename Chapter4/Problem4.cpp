#include <iostream>
#include <vector>
#include <cmath>  // Để dùng pow()
#include <iomanip>  // Để căn lề trong xuất kết quả
using namespace std;

class DaThuc {
private:
    vector<double> heSo;  // Mảng chứa các hệ số của đa thức

public:
    // 1. Khởi tạo đa thức với bậc n (n+1 hệ số)
    DaThuc(int n = 0) {
        heSo.resize(n + 1, 0);  // Khởi tạo mảng hệ số với giá trị 0
    }

    // 2. Nhập hệ số cho đa thức
    void Nhap() {
        cout << "Nhap bac cua da thuc: ";
        int n;
        cin >> n;
        heSo.resize(n + 1);  // Điều chỉnh kích thước mảng hệ số
        for (int i = n; i >= 0; --i) {
            cout << "Nhap he so cua x^" << i << ": ";
            cin >> heSo[i];
        }
    }

    // 3. Xuất đa thức ra màn hình
    void Xuat() const {
        bool isFirst = true;  // Để kiểm soát việc in dấu cộng
        for (int i = heSo.size() - 1; i >= 0; --i) {
            if (heSo[i] != 0) {
                if (!isFirst) cout << " + ";
                cout << heSo[i] << "x^" << i;
                isFirst = false;
            }
        }
        if (isFirst) cout << "0";  // Nếu tất cả hệ số đều là 0
        cout << endl;
    }

    // 4. Tính giá trị của đa thức tại một điểm x
    double TinhGiaTri(double x) const {
        double ketQua = 0;
        for (int i = 0; i < heSo.size(); ++i) {
            ketQua += heSo[i] * pow(x, i);
        }
        return ketQua;
    }

    // 5. Cộng hai đa thức
    DaThuc Cong(const DaThuc& other) const {
        int maxBac = max(heSo.size(), other.heSo.size());
        DaThuc ketQua(maxBac - 1);

        for (int i = 0; i < maxBac; ++i) {
            double hs1 = (i < heSo.size()) ? heSo[i] : 0;
            double hs2 = (i < other.heSo.size()) ? other.heSo[i] : 0;
            ketQua.heSo[i] = hs1 + hs2;
        }
        return ketQua;
    }

    // 6. Trừ hai đa thức
    DaThuc Tru(const DaThuc& other) const {
        int maxBac = max(heSo.size(), other.heSo.size());
        DaThuc ketQua(maxBac - 1);

        for (int i = 0; i < maxBac; ++i) {
            double hs1 = (i < heSo.size()) ? heSo[i] : 0;
            double hs2 = (i < other.heSo.size()) ? other.heSo[i] : 0;
            ketQua.heSo[i] = hs1 - hs2;
        }
        return ketQua;
    }
};

// Chương trình chính
int main() {
    DaThuc dt1, dt2;

    cout << "Nhap da thuc thu nhat:\n";
    dt1.Nhap();

    cout << "Nhap da thuc thu hai:\n";
    dt2.Nhap();

    cout << "Da thuc thu nhat: ";
    dt1.Xuat();

    cout << "Da thuc thu hai: ";
    dt2.Xuat();

    DaThuc tong = dt1.Cong(dt2);
    cout << "Tong hai da thuc: ";
    tong.Xuat();

    DaThuc hieu = dt1.Tru(dt2);
    cout << "Hieu hai da thuc: ";
    hieu.Xuat();

    double x;
    cout << "Nhap gia tri x de tinh P(x) cua da thuc thu nhat: ";
    cin >> x;
    cout << "P(" << x << ") = " << dt1.TinhGiaTri(x) << endl;

    return 0;
}
