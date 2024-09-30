#include <iostream>
#include <cmath>
using namespace std;

// Ham tinh sin(x) su dung chuoi Taylor
double tinhSin(double x) {
    double term = x;       // So hang dau tien la x
    double sinx = x;       // Gia tri ban dau cua sin(x) la x
    int n = 1;             // Bien dem de tinh cac so hang tiep theo
    const double epsilon = 0.00001;  // Do chinh xac

    while (fabs(term) > epsilon) {
        term *= (-1) * x * x / ((2 * n) * (2 * n + 1));  // Tinh so hang tiep theo
        sinx += term;  // Cong vao ket qua
        n++;           // Tang bien dem n
    }

    return sinx;
}

int main() {
    double x;
    cout << "Nhap x (radian): ";
    cin >> x;

    // Goi ham tinh sin(x)
    double result = tinhSin(x);

    // In ra ket qua
    cout << "Gia tri cua sin(" << x << ") voi do chinh xac 0.00001 la: " << result << endl;

    return 0;
}
