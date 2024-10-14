#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Fraction {
private:
    int numerator;   // Tu so
    int denominator; // Mau so

public:
    // Constructor de khoi tao phan so
    Fraction(int num = 0, int denom = 1) {
        numerator = num;
        setDenominator(denom);
    }

    // Kiem tra va dat mau so hop le
    void setDenominator(int denom) {
        while (denom == 0) {
            cout << "Mau so khong the bang 0! Nhap lai: ";
            cin >> denom;
        }
        denominator = denom;
    }

    // Nhap phan so tu nguoi dung
    void input() {
        cout << "Nhap tu so: ";
        cin >> numerator;
        cout << "Nhap mau so: ";
        int denom;
        cin >> denom;
        setDenominator(denom);
    }

    // Tinh gia tri thuc cua phan so
    double value() const {
        return static_cast<double>(numerator) / denominator;
    }

    // In ra phan so theo dinh dang "tu so / mau so"
    void print() const {
        cout << numerator << " / " << denominator;
    }
};

// Ham tim phan so lon nhat va nho nhat
void findMinMax(const vector<Fraction>& fractions, Fraction& minFrac, Fraction& maxFrac) {
    minFrac = fractions[0];
    maxFrac = fractions[0];

    for (const Fraction& frac : fractions) {
        if (frac.value() < minFrac.value()) {
            minFrac = frac;
        }
        if (frac.value() > maxFrac.value()) {
            maxFrac = frac;
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<Fraction> fractions(n);

    // Nhap tung phan so
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        fractions[i].input();
    }

    // Tim phan so nho nhat va lon nhat
    Fraction minFraction, maxFraction;
    findMinMax(fractions, minFraction, maxFraction);

    // Xuat ket qua
    cout << "Phan so nho nhat: ";
    minFraction.print();
    cout << "\nPhan so lon nhat: ";
    maxFraction.print();
    cout << endl;

    return 0;
}
