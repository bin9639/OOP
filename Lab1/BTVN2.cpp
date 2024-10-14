#include <iostream>
#include <vector>
#include <algorithm> // std::sort
using namespace std;

class Fraction {
public:
    int numerator;   // Tử số
    int denominator; // Mẫu số

    // Constructor
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    // Tính giá trị thực của phân số
    double value() const {
        return static_cast<double>(numerator) / denominator;
    }

    // In phân số
    void print() const {
        cout << numerator << " / " << denominator;
    }
};

// Hàm so sánh giá trị thực của hai phân số
bool compare(const Fraction& a, const Fraction& b) {
    return a.value() < b.value();
}

int main() {
    int n, k;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    cout << "Nhap so nguyen duong k: ";
    cin >> k;

    // Nhập danh sách phân số
    vector<Fraction> fractions(n);
    for (int i = 0; i < n; ++i) {
        int num, denom;
        cout << "Nhap tu so va mau so cua phan so thu " << i + 1 << ": ";
        cin >> num >> denom;
        while (denom == 0) { // Kiểm tra mẫu số hợp lệ
            cout << "Mau so khong the bang 0! Nhap lai: ";
            cin >> denom;
        }
        fractions[i] = Fraction(num, denom);
    }

    // Sắp xếp các phân số theo giá trị thực
    sort(fractions.begin(), fractions.end(), compare);

    // Kiểm tra và in phân số bé thứ k
    if (k <= n) {
        cout << "Phan so be thu " << k << ": ";
        fractions[k - 1].print();
        cout << endl;
    }

    // Kiểm tra và in phân số lớn thứ k
    if (k <= n) {
        cout << "Phan so lon thu " << k << ": ";
        fractions[n - k].print();
        cout << endl;
    }

    return 0;
}
