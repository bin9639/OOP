// main.cpp
#include "thoigian.h"

int main() {
    ThoiGian tg1, tg2;

    cout << "Nhap thoi gian thu nhat:\n";
    cin >> tg1;
    cout << "Nhap thoi gian thu hai:\n";
    cin >> tg2;

    cout << "Tong thoi gian: " << tg1 + tg2 << endl;
    cout << "Hieu thoi gian: " << tg1 - tg2 << endl;

    int seconds;
    cout << "Nhap so giay de cong vao thoi gian thu nhat: ";
    cin >> seconds;
    cout << "Ket qua sau khi cong " << seconds << " giay: " << tg1 + seconds << endl;

    cout << "Nhap so giay de tru khoi thoi gian thu nhat: ";
    cin >> seconds;
    cout << "Ket qua sau khi tru " << seconds << " giay: " << tg1 - seconds << endl;

    cout << "Tang thoi gian thu nhat len 1 giay: " << ++tg1 << endl;
    cout << "Giam thoi gian thu nhat xuong 1 giay: " << --tg1 << endl;

    cout << "So sanh thoi gian: ";
    if (tg1 == tg2) cout << "Thoi gian bang nhau.\n";
    else if (tg1 > tg2) cout << "Thoi gian thu nhat lon hon thoi gian thu hai.\n";
    else cout << "Thoi gian thu nhat nho hon thoi gian thu hai.\n";

    return 0;
}
