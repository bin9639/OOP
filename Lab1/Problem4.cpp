#include <iostream>
using namespace std;

class Ngay {
private:
    int ngay, thang, nam;

    // Hàm kiểm tra năm nhuận
    bool namNhuan(int nam) {
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    }

    // Hàm kiểm tra số ngày trong tháng
    int soNgayTrongThang(int thang, int nam) {
        if (thang == 2) {
            return namNhuan(nam) ? 29 : 28;
        } else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
            return 30;
        } else {
            return 31;
        }
    }

public:
    // Hàm nhập ngày
    void nhap() {
        cout << "Nhap ngay (dd mm yyyy): ";
        cin >> ngay >> thang >> nam;
        while (thang < 1 || thang > 12 || ngay < 1 || ngay > soNgayTrongThang(thang, nam)) {
            cout << "Ngay khong hop le. Nhap lai: ";
            cin >> ngay >> thang >> nam;
        }
    }

    // Hàm tìm ngày kế tiếp
    Ngay ngayKeTiep() {
        Ngay next = *this;
        next.ngay++;
        if (next.ngay > soNgayTrongThang(next.thang, next.nam)) {
            next.ngay = 1;
            next.thang++;
            if (next.thang > 12) {
                next.thang = 1;
                next.nam++;
            }
        }
        return next;
    }

    // Hàm tìm ngày trước
    Ngay ngayTruoc() {
        Ngay prev = *this;
        prev.ngay--;
        if (prev.ngay < 1) {
            prev.thang--;
            if (prev.thang < 1) {
                prev.thang = 12;
                prev.nam--;
            }
            prev.ngay = soNgayTrongThang(prev.thang, prev.nam);
        }
        return prev;
    }

    // Hàm tính số thứ tự trong năm
    int soThuTuTrongNam() {
        int soNgay = 0;
        for (int i = 1; i < thang; i++) {
            soNgay += soNgayTrongThang(i, nam);
        }
        soNgay += ngay;
        return soNgay;
    }

    // Hàm xuất ngày
    void xuat() {
        cout << "Ngay: " << ngay << "/" << thang << "/" << nam << endl;
    }
};

int main() {
    Ngay date;
    date.nhap();

    Ngay nextDay = date.ngayKeTiep();
    cout << "Ngay ke tiep: ";
    nextDay.xuat();

    Ngay prevDay = date.ngayTruoc();
    cout << "Ngay truoc: ";
    prevDay.xuat();

    int dayOfYear = date.soThuTuTrongNam();
    cout << "Ngay thu " << dayOfYear << " trong nam." << endl;

    return 0;
}
