#include <iostream>
#include <vector>
#include <cstdlib>   // Để dùng hàm rand(), srand()
#include <ctime>     // Để khởi tạo seed cho rand()
#include <algorithm> // Để dùng hàm sort()
#include <numeric>   // Để dùng hàm gcd()

// Lớp PhanSo đại diện cho một phân số với tử và mẫu
class PhanSo {
public:
    int tu;   // Tử số
    int mau;  // Mẫu số

    // Constructor mặc định
    PhanSo(int tu = 0, int mau = 1) : tu(tu), mau(mau) {
        if (mau == 0) throw std::invalid_argument("Mau so phai khac 0");
        RutGon();
    }

    // Rút gọn phân số bằng cách chia cho ước chung lớn nhất (gcd)
    void RutGon() {
        int ucln = std::__gcd(tu, mau);
        tu /= ucln;
        mau /= ucln;
        if (mau < 0) {  // Đưa mẫu dương nếu cần
            tu = -tu;
            mau = -mau;
        }
    }

    // Tính giá trị thực của phân số
    double GiaTri() const {
        return static_cast<double>(tu) / mau;
    }

    // Toán tử so sánh phân số để sắp xếp
    bool operator<(const PhanSo& other) const {
        return GiaTri() < other.GiaTri();
    }

    // In phân số ra màn hình
    void Xuat() const {
        std::cout << tu << "/" << mau << " ";
    }

    // Kiểm tra xem tử số có phải số nguyên tố không
    bool TuSoNguyenTo() const {
        if (tu < 2) return false;
        for (int i = 2; i * i <= tu; ++i) {
            if (tu % i == 0) return false;
        }
        return true;
    }
};

// Lớp arrPhanSo để lưu trữ và thao tác trên mảng phân số
class arrPhanSo {
private:
    std::vector<PhanSo> data;  // Mảng các phân số

public:
    // 1. Nhập các phân số từ người dùng
    void NhapPhanSo(int n) {
        data.clear();
        int tu, mau;
        for (int i = 0; i < n; ++i) {
            std::cout << "Nhap phan so thu " << i + 1 << " (tu mau): ";
            std::cin >> tu >> mau;
            data.emplace_back(tu, mau);
        }
    }

    // 2. Xuất danh sách các phân số
    void XuatPhanSo() const {
        std::cout << "Danh sach phan so: ";
        for (const auto& ps : data) {
            ps.Xuat();
        }
        std::cout << std::endl;
    }

    // 3. Tạo n phân số ngẫu nhiên
    void TaoNgauNhien(int n) {
        data.clear();
        srand(time(0));  // Khởi tạo seed cho hàm rand()
        for (int i = 0; i < n; ++i) {
            int tu = rand() % 21 - 10;  // Tạo tử từ -10 đến 10
            int mau;
            do {
                mau = rand() % 10 + 1;  // Mẫu từ 1 đến 10
            } while (mau == 0);
            data.emplace_back(tu, mau);
        }
    }

    // 4. Tìm phân số có giá trị lớn nhất
    PhanSo TimPhanSoLonNhat() const {
        return *std::max_element(data.begin(), data.end());
    }

    // 5. Đếm số phân số có tử là số nguyên tố
    int DemTuSoNguyenTo() const {
        int count = 0;
        for (const auto& ps : data) {
            if (ps.TuSoNguyenTo()) ++count;
        }
        return count;
    }

    // 6. Sắp xếp các phân số theo thứ tự tăng dần
    void SapXepTangDan() {
        std::sort(data.begin(), data.end());
    }
};

// Hàm main để kiểm tra các chức năng của lớp arrPhanSo
int main() {
    arrPhanSo arr;
    int n;

    std::cout << "Nhap so luong phan so: ";
    std::cin >> n;

    arr.NhapPhanSo(n);
    arr.XuatPhanSo();

    std::cout << "Tao mang phan so ngau nhien:\n";
    arr.TaoNgauNhien(n);
    arr.XuatPhanSo();

    PhanSo maxPS = arr.TimPhanSoLonNhat();
    std::cout << "Phan so co gia tri lon nhat: ";
    maxPS.Xuat();
    std::cout << std::endl;

    int countPrimeTu = arr.DemTuSoNguyenTo();
    std::cout << "So phan so co tu so nguyen to: " << countPrimeTu << std::endl;

    std::cout << "Mang phan so sau khi sap xep tang dan:\n";
    arr.SapXepTangDan();
    arr.XuatPhanSo();

    return 0;
}
