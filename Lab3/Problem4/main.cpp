// main.cpp
#include "ngaythangnam.h"

int main() {
    NgayThangNam nt1, nt2;

    cout << "Nhap ngay thang nam thu nhat:\n";
    cin >> nt1;
    cout << "Nhap ngay thang nam thu hai:\n";
    cin >> nt2;

    cout << "Tong cua ngay thang nam thu nhat va 10 ngay: " << nt1 + 10 << endl;
    cout << "Hieu cua ngay thang nam thu nhat va 5 ngay: " << nt1 - 5 << endl;
    cout << "Khoang cach giua hai ngay: " << nt1 - nt2 << " ngay" << endl;

    cout << "Tang ngay thang nam thu nhat len 1 ngay: " << ++nt1 << endl;
    cout << "Giam ngay thang nam thu nhat xuong 1 ngay: " << --nt1 << endl;

    cout << "So sanh ngay thang nam: ";
    if (nt1 == nt2) cout << "Ngay thang nam bang nhau.\n";
    else if (nt1 > nt2) cout << "Ngay thang nam thu nhat lon hon ngay thang nam thu hai.\n";
    else cout << "Ngay thang nam thu nhat nho hon ngay thang nam thu hai.\n";

    return 0;
}
