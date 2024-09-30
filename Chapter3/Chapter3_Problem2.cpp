#include <iostream>
#include <cmath>
using namespace std;

const float M_PI = acos(-1);

class Circle {
private:
    float x;        // Tọa độ x của tâm đường tròn
    float y;        // Tọa độ y của tâm đường tròn
    float radius;   // Bán kính của đường tròn

public:
    // Hàm khởi tạo
    Circle(float centerX, float centerY, float r) {
        x = centerX;
        y = centerY;
        radius = r;
    }

    // Hàm tính chu vi
    float calcPerimeter() {
        return 2 * M_PI * radius;
    }

    // Hàm tính diện tích
    float calcArea() {
        return M_PI * radius * radius;
    }

    // Hàm xuất thông tin
    void displayResult() {
        cout << "Tọa độ tâm đường tròn: (" << x << ", " << y << ")" << endl;
        cout << "Bán kính đường tròn: " << radius << endl;
        cout << "Chu vi đường tròn: " << calcPerimeter() << endl;
        cout << "Diện tích đường tròn: " << calcArea() << endl;
    }
};

int main() {
    float centerX, centerY, radius;

    // Nhập tọa độ tâm và bán kính đường tròn
    cout << "Nhập tọa độ x của tâm: ";
    cin >> centerX;
    cout << "Nhập tọa độ y của tâm: ";
    cin >> centerY;
    cout << "Nhập bán kính của đường tròn: ";
    cin >> radius;

    // Tạo đối tượng Circle và xuất kết quả
    Circle circle(centerX, centerY, radius);
    circle.displayResult();

    return 0;
}
