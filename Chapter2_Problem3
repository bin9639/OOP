#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vect    or<vector<int>> mat;
    int rows, cols;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(r, vector<int>(c, 0));
    }

    // Nhập ma trận
    void input() {
        cout << "Nhap cac phan tu cua ma tran (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Phan tu [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> mat[i][j];
            }
        }
    }

    // In ma trận
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Phép nhân ma trận
    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;
    cout << "Nhap hang va cot cua ma tran 1\n";
    cin >> r1 >> c1;
    Matrix mat1(r1, c1);
    mat1.input();

    cout << "Nhap hang va cot cua ma tran 2\n";
    cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    mat2.input();

    // Tích hai ma trận
    Matrix product = mat1 * mat2;
    cout << "Tich 2 ma tran:\n";
    product.print();

    return 0;
}
