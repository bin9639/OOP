// main.cpp
#include "sophuc.h"

int main() {
    SoPhuc sp1, sp2;

    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;
    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;

    // Các phép toán
    cout << "Tong: " << sp1 + sp2 << endl;
    cout << "Hieu: " << sp1 - sp2 << endl;
    cout << "Tich: " << sp1 * sp2 << endl;
    cout << "Thuong: " << sp1 / sp2 << endl;

    // Các phép so sánh
    cout << "So phuc thu nhat " << (sp1 == sp2 ? "bang" : "khong bang") << " so phuc thu hai\n";
    cout << "So phuc thu nhat " << (sp1 != sp2 ? "khac" : "khong khac") << " so phuc thu hai\n";

    return 0;
}
