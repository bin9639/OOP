#include <iostream>
using namespace std;

class Diem {
private:
    int iHoanh; // Hoành độ
    int iTung;  // Tung độ

public:
    // Constructor mặc định
    Diem() : iHoanh(0), iTung(0) {}

    // Constructor có tham số
    Diem(int Hoanh, int Tung) : iHoanh(Hoanh), iTung(Tung) {}

    // Constructor sao chép
    Diem(const Diem &x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

    // Phương thức xuất thông tin điểm
    void Xuat() const {
        cout << "Diem(" << iHoanh << ", " << iTung << ")\n";
    }

    // Getter cho tung độ
    int GetTungDo() const {
        return iTung;
    }

    // Getter cho hoành độ
    int GetHoanhDo() const {
        return iHoanh;
    }

    // Setter cho tung độ
    void SetTungDo(int Tung) {
        iTung = Tung;
    }

    // Setter cho hoành độ
    void SetHoanhDo(int Hoanh) {
        iHoanh = Hoanh;
    }

    // Phương thức tịnh tiến điểm
    void TinhTien(int dx, int dy) {
        iHoanh += dx;
        iTung += dy;
    }
};

int main() {
    // Tạo đối tượng Diem bằng constructor mặc định
    Diem d1;
    cout << "Diem d1: ";
    d1.Xuat();

    // Tạo đối tượng Diem bằng constructor có tham số
    Diem d2(3, 4);
    cout << "Diem d2: ";
    d2.Xuat();

    // Tạo đối tượng Diem bằng constructor sao chép
    Diem d3(d2);
    cout << "Diem d3 (sao chep tu d2): ";
    d3.Xuat();

    // Thay đổi giá trị hoành độ và tung độ của d1
    d1.SetHoanhDo(1);
    d1.SetTungDo(2);
    cout << "Diem d1 sau khi thay doi: ";
    d1.Xuat();

    // Lấy giá trị hoành độ và tung độ của d2
    cout << "Hoanh do cua d2: " << d2.GetHoanhDo() << "\n";
    cout << "Tung do cua d2: " << d2.GetTungDo() << "\n";

    // Tịnh tiến điểm d3
    d3.TinhTien(2, -1);
    cout << "Diem d3 sau khi tinh tien (2, -1): ";
    d3.Xuat();

    return 0;
}
