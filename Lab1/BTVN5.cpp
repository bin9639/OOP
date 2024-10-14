#include <iostream>
#include <vector>
#include <algorithm>  // std::sort
using namespace std;

// Lớp Rectangle đại diện cho một hình chữ nhật
class Rectangle {
public:
    int x, y, width, height;

    // Constructor
    Rectangle(int x, int y, int w, int h) 
        : x(x), y(y), width(w), height(h) {}

    // Phương thức in ra thông tin hình chữ nhật
    void print() const {
        cout << "[" << x << ", " << y << ", " 
             << width << ", " << height << "]\n";
    }
};

// So sánh để sắp xếp các hình chữ nhật từ trái sang phải và từ trên xuống dưới
bool compareRectangles(const Rectangle& a, const Rectangle& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

// Lớp BinaryMatrix quản lý ma trận và tìm các hình chữ nhật
class BinaryMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<bool>> visited;
    int m, n;

public:
    // Constructor khởi tạo ma trận và visited
    BinaryMatrix(int rows, int cols) : m(rows), n(cols) {
        matrix.resize(m, vector<int>(n));
        visited.resize(m, vector<bool>(n, false));
    }

    // Nhập dữ liệu cho ma trận
    void inputMatrix() {
        cout << "Nhap ma tran:\n";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
    }

    // Tìm tất cả các hình chữ nhật trong ma trận
    vector<Rectangle> findRectangles() {
        vector<Rectangle> rectangles;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1 && !visited[i][j]) {
                    Rectangle rect = exploreRectangle(i, j);
                    if (rect.width >= 2 && rect.height >= 2) {
                        rectangles.push_back(rect);
                    }
                }
            }
        }

        // Sắp xếp các hình chữ nhật theo thứ tự từ trái sang phải, từ trên xuống dưới
        sort(rectangles.begin(), rectangles.end(), compareRectangles);
        return rectangles;
    }

private:
    // Khám phá hình chữ nhật từ một điểm (x, y)
    Rectangle exploreRectangle(int x, int y) {
        int width = 0, height = 0;

        // Tìm chiều rộng
        while (y + width < n && matrix[x][y + width] == 1) {
            ++width;
        }

        // Tìm chiều cao
        bool validRectangle = true;
        while (x + height < m && validRectangle) {
            for (int k = y; k < y + width; ++k) {
                if (matrix[x + height][k] != 1) {
                    validRectangle = false;
                    break;
                }
            }
            if (validRectangle) ++height;
        }

        // Đánh dấu các phần tử đã được bao
        for (int i = x; i < x + height; ++i) {
            for (int j = y; j < y + width; ++j) {
                visited[i][j] = true;
            }
        }

        return Rectangle(x, y, width, height);
    }
};

int main() {
    int m, n;
    cout << "Nhap kich thuoc ma tran (m n): ";
    cin >> m >> n;

    BinaryMatrix matrix(m, n);
    matrix.inputMatrix();

    // Tìm và in danh sách các hình chữ nhật
    vector<Rectangle> rectangles = matrix.findRectangles();
    if (rectangles.empty()) {
        cout << "Khong tim thay hinh chu nhat thoa man.\n";
    } else {
        cout << "Danh sach hinh chu nhat:\n";
        for (const Rectangle& rect : rectangles) {
            rect.print();
        }
    }

    return 0;
}
