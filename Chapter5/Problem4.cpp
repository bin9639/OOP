#include <iostream>
#include <vector>
#include <cstdlib>  // std::rand, std::srand
#include <ctime>    // std::time
using namespace std;

class MaTran {
private:
    vector<vector<int>> data;
    int rows, cols;

public:
    // Constructor mặc định: Khởi tạo ma trận m x n với các phần tử bằng 0
    MaTran(int m = 0, int n = 0) : rows(m), cols(n) {
        data.resize(m, vector<int>(n, 0));
    }

    // Nhập ma trận từ bàn phím
    void Nhap() {
        cout << "Nhap so dong: ";
        cin >> rows;
        cout << "Nhap so cot: ";
        cin >> cols;
        data.resize(rows, vector<int>(cols));

        cout << "Nhap cac phan tu cua ma tran:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "a[" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }

    // Tạo ma trận ngẫu nhiên với các giá trị trong khoảng [0, 9]
    void TaoNgauNhien(int m, int n) {
        rows = m;
        cols = n;
        data.resize(m, vector<int>(n));

        std::srand(std::time(0));  // Khởi tạo seed cho số ngẫu nhiên
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] = std::rand() % 10;  // Giá trị ngẫu nhiên [0, 9]
            }
        }
    }

    // Xuất ma trận ra màn hình
    void Xuat() const {
        for (const auto& row : data) {
            for (int elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    // Operator cộng hai ma trận
    MaTran operator+(const MaTran& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Hai ma tran phai co cung kich thuoc!");
        }
        MaTran result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Operator nhân hai ma trận
    MaTran operator*(const MaTran& other) const {
        if (cols != other.rows) {
            throw invalid_argument("So cot cua ma tran 1 phai bang so dong cua ma tran 2!");
        }
        MaTran result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    try {
        // Tạo và nhập ma trận 1
        MaTran A;
        cout << "Nhap ma tran A:\n";
        A.Nhap();

        // Tạo và nhập ma trận 2
        MaTran B;
        cout << "Nhap ma tran B:\n";
        B.Nhap();

        // Cộng hai ma trận
        cout << "\nTong cua hai ma tran A + B:\n";
        MaTran C = A + B;
        C.Xuat();

        // Nhân hai ma trận
        cout << "\nTich cua hai ma tran A * B:\n";
        MaTran D = A * B;
        D.Xuat();
    } catch (const invalid_argument& e) {
        cerr << "Loi: " << e.what() << endl;
    }

    return 0;
}
