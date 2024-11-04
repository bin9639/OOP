#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc;  // Phần thực
    double ao;    // Phần ảo

public:
    // 1. Khởi tạo mặc định và có tham số (số thực được xem là số phức với phần ảo bằng 0)
    SoPhuc(double thuc = 0, double ao = 0) : thuc(thuc), ao(ao) {}

    // 2. Nhập số phức từ bàn phím
    friend istream& operator>>(istream& is, SoPhuc& sp) {
        cout << "Nhap phan thuc: ";
        is >> sp.thuc;
        cout << "Nhap phan ao: ";
        is >> sp.ao;
        return is;
    }

    // 3. Xuất số phức ra màn hình
    friend ostream& operator<<(ostream& os, const SoPhuc& sp) {
        os << sp.thuc;
        if (sp.ao >= 0)
            os << " + " << sp.ao << "i";
        else
            os << " - " << -sp.ao << "i";
        return os;
    }

    // 4. Định nghĩa toán tử cộng (+)
    SoPhuc operator+(const SoPhuc& other) const {
        return SoPhuc(thuc + other.thuc, ao + other.ao);
    }

    // 5. Định nghĩa toán tử trừ (-)
    SoPhuc operator-(const SoPhuc& other) const {
        return SoPhuc(thuc - other.thuc, ao - other.ao);
    }

    // 6. Định nghĩa toán tử nhân (*)
    SoPhuc operator*(const SoPhuc& other) const {
        double newThuc = thuc * other.thuc - ao * other.ao;
        double newAo = thuc * other.ao + ao * other.thuc;
        return SoPhuc(newThuc, newAo);
    }

    // 7. Định nghĩa toán tử chia (/)
    SoPhuc operator/(const SoPhuc& other) const {
        double mau = other.thuc * other.thuc + other.ao * other.ao;
        double newThuc = (thuc * other.thuc + ao * other.ao) / mau;
        double newAo = (ao * other.thuc - thuc * other.ao) / mau;
        return SoPhuc(newThuc, newAo);
    }

    // 8. Định nghĩa toán tử so sánh bằng (==)
    bool operator==(const SoPhuc& other) const {
        return thuc == other.thuc && ao == other.ao;
    }
};

int main() {
    SoPhuc sp1, sp2;

    // Nhập hai số phức
    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;
    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;

    // Xuất hai số phức
    cout << "So phuc thu nhat: " << sp1 << endl;
    cout << "So phuc thu hai: " << sp2 << endl;

    // Thực hiện các phép toán
    cout << "Tong: " << sp1 + sp2 << endl;
    cout << "Hieu: " << sp1 - sp2 << endl;
    cout << "Tich: " << sp1 * sp2 << endl;
    cout << "Thuong: " << sp1 / sp2 << endl;

    // Kiểm tra hai số phức có bằng nhau không
    if (sp1 == sp2)
        cout << "Hai so phuc bang nhau." << endl;
    else
        cout << "Hai so phuc khong bang nhau." << endl;

    return 0;
}

