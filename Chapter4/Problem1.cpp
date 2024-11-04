#include <iostream>
#include <vector>
#include <cstdlib> // Để sử dụng hàm rand() và srand()
#include <ctime>   // Để khởi tạo seed cho hàm rand()
#include <algorithm> // Để sử dụng hàm sort()
#include <limits>   // Để lấy giá trị lớn nhất INT_MAX

class cArray {
private:
    std::vector<int> data;  // Mảng một chiều lưu trữ các số nguyên

public:
    // 1. Nhập dãy số nguyên gồm n phần tử
    void NhapMang(int n) {
        int value;
        data.clear();  // Xóa mảng cũ nếu có
        std::cout << "Nhap " << n << " so nguyen:\n";
        for (int i = 0; i < n; ++i) {
            std::cout << "Phan tu [" << i << "]: ";
            std::cin >> value;
            data.push_back(value);
        }
    }

    // 2. Xuất dãy số nguyên của mảng
    void XuatMang() const {
        std::cout << "Mang: ";
        for (int val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // 3. Tạo dãy gồm n số nguyên ngẫu nhiên
    void TaoMangNgauNhien(int n, int min = 0, int max = 100) {
        data.clear();  // Xóa mảng cũ nếu có
        srand(time(0)); // Khởi tạo seed cho hàm rand()
        for (int i = 0; i < n; ++i) {
            int randomValue = min + rand() % (max - min + 1);
            data.push_back(randomValue);
        }
    }

    // 4. Đếm số lần xuất hiện của x trong mảng
    int DemSoLanXuatHien(int x) const {
        int count = 0;
        for (int val : data) {
            if (val == x) ++count;
        }
        return count;
    }

    // 5. Kiểm tra dãy số nguyên có tăng dần hay không
    bool KiemTraTangDan() const {
        for (size_t i = 1; i < data.size(); ++i) {
            if (data[i] < data[i - 1]) return false;
        }
        return true;
    }

    // 6. Tìm phần tử lẻ nhỏ nhất trong dãy số nguyên
    int TimSoLeNhoNhat() const {
        int minOdd = std::numeric_limits<int>::max(); // INT_MAX
        bool found = false;

        for (int val : data) {
            if (val % 2 != 0 && val < minOdd) {
                minOdd = val;
                found = true;
            }
        }
        return found ? minOdd : -1; // Trả về -1 nếu không tìm thấy số lẻ
    }

    // 7. Sắp xếp các số nguyên trong dãy tăng dần
    void SapXepTangDan() {
        std::sort(data.begin(), data.end());
    }
};

// Hàm main để thử nghiệm các chức năng của lớp cArray
int main() {
    cArray arr;
    int n, x;

    std::cout << "Nhap so phan tu: ";
    std::cin >> n;

    arr.NhapMang(n);
    arr.XuatMang();

    std::cout << "Nhap so x de dem so lan xuat hien: ";
    std::cin >> x;
    std::cout << "So lan xuat hien cua " << x << ": " << arr.DemSoLanXuatHien(x) << std::endl;

    std::cout << "Mang co tang dan? " << (arr.KiemTraTangDan() ? "Co" : "Khong") << std::endl;

    int minOdd = arr.TimSoLeNhoNhat();
    if (minOdd != -1)
        std::cout << "So le nho nhat: " << minOdd << std::endl;
    else
        std::cout << "Khong co so le trong mang.\n";

    arr.SapXepTangDan();
    std::cout << "Mang sau khi sap xep tang dan: ";
    arr.XuatMang();

    std::cout << "\nTao mang ngau nhien: ";
    arr.TaoMangNgauNhien(n);
    arr.XuatMang();

    return 0;
}
