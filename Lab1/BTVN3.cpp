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

    // Nhân hai phân số
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Kiểm tra hai phân số có bằng nhau không
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == denominator * other.numerator;
    }
};

// Hàm so sánh giá trị thực của hai phân số (dùng cho sắp xếp)
bool compare(const Fraction& a, const Fraction& b) {
    return a.value() < b.value();
}

// Hàm tìm tập hợp con có tích bằng phân số đích
void findSubsetWithTargetProduct(const vector<Fraction>& fractions, const Fraction& target) {
    int n = fractions.size();
    vector<Fraction> bestSubset; // Tập hợp con có ít phần tử nhất

    // Duyệt tất cả các tập hợp con (2^n tập hợp con)
    for (int mask = 1; mask < (1 << n); ++mask) {
        Fraction product(1, 1); // Tích các phân số trong tập hợp con hiện tại
        vector<Fraction> subset;

        // Duyệt từng phần tử trong mảng để xây dựng tập hợp con
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // Nếu bit thứ i bật, chọn phân số i vào tập hợp con
                product = product * fractions[i];
                subset.push_back(fractions[i]);
            }
        }

        // Kiểm tra nếu tích bằng phân số đích và tập hợp con này ít phần tử hơn
        if (product == target &&
            (bestSubset.empty() || subset.size() < bestSubset.size())) {
            bestSubset = subset; // Cập nhật tập hợp con tốt nhất
        }
    }

    // Xuất kết quả
    if (!bestSubset.empty()) {
        sort(bestSubset.begin(), bestSubset.end(), compare); // Sắp xếp theo giá trị thực
        cout << "Tap hop con co tich bang phan so dich: ";
        for (const Fraction& frac : bestSubset) {
            frac.print();
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

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

    int targetNum, targetDenom;
    cout << "Nhap tu so va mau so cua phan so dich: ";
    cin >> targetNum >> targetDenom;
    Fraction target(targetNum, targetDenom);

    findSubsetWithTargetProduct(fractions, target);

    return 0;
}
