#include <iostream>
#include <string>
using namespace std;

class Student {
private:
     string name;
    float mathScore;
    float literatureScore;

public:
    // Hàm khởi tạo
    Student(string n, float math, float literature) {
        name = n;
        mathScore = math;
        literatureScore = literature;
    }

    // Hàm tính điểm trung bình
    float calcAverage() {
        return (mathScore + literatureScore) / 2;
    }

    // Hàm xếp loại
    string classify() {
        float average = calcAverage();
        if (average >= 9.0) return "Xuất sắc";
        else if (average >= 8.0) return "Giỏi";
        else if (average >= 6.5) return "Khá";
        else if (average >= 5.0) return "Trung bình";
        else return "Yếu";
    }

    // Hàm xuất thông tin
    void displayResult() {
        cout << "Họ và tên: " << name << endl;
        cout << "Điểm Toán: " << mathScore << endl;
        cout << "Điểm Văn: " << literatureScore << endl;
        cout << "Điểm trung bình: " << calcAverage() << endl;
        cout << "Xếp loại: " << classify() << endl;
    }
};

int main() {
    string name;    
    
    float mathScore, literatureScore;

    // Nhập thông tin học sinh
    cout << "Nhập họ và tên học sinh: ";
    getline(cin, name);
    cout << "Nhập điểm Toán: ";
    cin >> mathScore;
    cout << "Nhập điểm Văn: ";
    cin >> literatureScore;

    // Tạo đối tượng Student và xuất kết quả
    Student student(name, mathScore, literatureScore);
    student.displayResult();

    return 0;
}
