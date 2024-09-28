#include <iostream>
#include <string>

using namespace std;

// Lớp Học Sinh
class Student {
private:
    string studentID;  // Mã học sinh
    string fullName;   // Họ và tên
    string gender;     // Giới tính
    float mathScore;   // Điểm Toán
    float literatureScore; // Điểm Lý
    float englishScore; // Điểm Hóa

public:
    // Hàm nhập thông tin học sinh
    void input() {
        cout << "Ma so sinh vien: ";
        getline(cin, studentID);
        cout << "Ho Ten sinh vien: ";
        getline(cin, fullName);
        cout << "Gioi tinh: ";
        getline(cin, gender);
        cout << "Diem Toan: ";
        cin >> mathScore;
        cout << "Diem Van: ";
        cin >> literatureScore;
        cout << "Diem Anh: ";
        cin >> englishScore;
    }

    // Hàm tính điểm trung bình
    float calculateAverageScore() const {
        return (mathScore + literatureScore + englishScore) / 3;
    }

    // Hàm xuất thông tin chi tiết của học sinh
    void print() const {
        cout << "Ma so sinh vien: "<<studentID<<endl;
         cout << "Ho Ten sinh vien: "<<fullName<<endl;
         cout << "Gioi tinh: "<<gender<<endl;
         cout << "Diem Toan: "<<mathScore<<endl;
         cout << "Diem Van: "<<literatureScore<<endl;
         cout << "Diem Anh: "<<englishScore<<endl;
         cout<<"Diem trung binh: "<<calculateAverageScore()<<endl;
    }
};

int main() {
    // Tạo đối tượng học sinh
    Student student;

    // Nhập thông tin học sinh
    student.input();

    // Xuất thông tin chi tiết học sinh
    student.print();

    return 0;
}
