#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    float x;  // Tọa độ x của điểm
    float y;  // Tọa độ y của điểm

public:
    // Hàm khởi tạo
    Point(float xCoord, float yCoord) {
        x = xCoord;
        y = yCoord;
    }

    // Hàm lấy tọa độ x
    float getX() {
        return x;
    }

    // Hàm lấy tọa độ y
    float getY() {
        return y;
    }

    // Hàm tính khoảng cách giữa hai điểm
    static float calcDistance(Point p1, Point p2) {
        return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    }
};

int main() {
    float x1, y1, x2, y2;

    // Nhập tọa độ điểm thứ nhất
    cout << "Nhập tọa độ x của điểm thứ nhất: ";
    cin >> x1;
    cout << "Nhập tọa độ y của điểm thứ nhất: ";
    cin >> y1;

    // Nhập tọa độ điểm thứ hai
    cout << "Nhập tọa độ x của điểm thứ hai: ";
    cin >> x2;
    cout << "Nhập tọa độ y của điểm thứ hai: ";
    cin >> y2;

    // Tạo hai đối tượng Point
    Point p1(x1, y1);
    Point p2(x2, y2);

    // Tính khoảng cách giữa hai điểm và xuất kết quả
    float distance = Point::calcDistance(p1, p2);
    cout << "Khoảng cách giữa hai điểm là: " << distance << endl;

    return 0;
}
