#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <regex>

using namespace std;

struct Date {
    int day, month, year;
};

struct Time {
    int hour, minute;
};

class Flight {
private:
    string flightCode;
    Date flightDate;
    Time flightTime;
    string departure;
    string destination;

public:
    // Hàm kiểm tra hợp lệ của mã chuyến bay
    bool validateFlightCode(const string& code) {
        return regex_match(code, regex("^[A-Za-z0-9]{1,5}$"));
    }

    // Hàm kiểm tra hợp lệ của nơi đi/nơi đến
    bool validatePlace(const string& place) {
        return regex_match(place, regex("^[A-Za-z ]{1,20}$"));
    }

    // Hàm kiểm tra hợp lệ của ngày
    bool validateDate(const Date& d) {
        if (d.month < 1 || d.month > 12 || d.day < 1 || d.year < 1) return false;
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
            daysInMonth[2] = 29; // Năm nhuận
        }
        return d.day <= daysInMonth[d.month];
    }

    // Hàm kiểm tra hợp lệ của giờ
    bool validateTime(const Time& t) {
        return t.hour >= 0 && t.hour < 24 && t.minute >= 0 && t.minute < 60;
    }

    // Hàm nhập thông tin chuyến bay
    void inputFlight() {
        do {
            cout << "Nhap ma chuyen bay (toi da 5 ky tu): ";
            cin >> flightCode;
        } while (!validateFlightCode(flightCode));

        do {
            cout << "Nhap ngay bay (dd mm yyyy): ";
            cin >> flightDate.day >> flightDate.month >> flightDate.year;
        } while (!validateDate(flightDate));

        do {
            cout << "Nhap gio bay (hh mm): ";
            cin >> flightTime.hour >> flightTime.minute;
        } while (!validateTime(flightTime));

        do {
            cout << "Nhap noi di (toi da 20 ky tu): ";
            cin.ignore();
            getline(cin, departure);
        } while (!validatePlace(departure));

        do {
            cout << "Nhap noi den (toi da 20 ky tu): ";
            getline(cin, destination);
        } while (!validatePlace(destination));
    }

    // Hàm xuất thông tin chuyến bay
    void displayFlight() const {
        cout << setw(6) << flightCode << " | " << setw(2) << setfill('0') << flightDate.day << "/"
             << setw(2) << setfill('0') << flightDate.month << "/" << flightDate.year << " | "
             << setw(2) << setfill('0') << flightTime.hour << ":" << setw(2) << setfill('0') << flightTime.minute
             << " | " << setw(20) << departure << " | " << setw(20) << destination << endl;
    }

    // Hàm so sánh ngày giờ
    bool operator<(const Flight& other) const {
        if (flightDate.year != other.flightDate.year)
            return flightDate.year < other.flightDate.year;
        if (flightDate.month != other.flightDate.month)
            return flightDate.month < other.flightDate.month;
        if (flightDate.day != other.flightDate.day)
            return flightDate.day < other.flightDate.day;
        if (flightTime.hour != other.flightTime.hour)
            return flightTime.hour < other.flightTime.hour;
        return flightTime.minute < other.flightTime.minute;
    }

    // Hàm trả về nơi đi
    string getDeparture() const {
        return departure;
    }

    // Hàm trả về nơi đến
    string getDestination() const {
        return destination;
    }

    // Hàm trả về mã chuyến bay
    string getFlightCode() const {
        return flightCode;
    }

    // Hàm trả về ngày khởi hành
    Date getFlightDate() const {
        return flightDate;
    }
};

// Hàm tìm chuyến bay theo mã chuyến bay
Flight* findFlightByCode(vector<Flight>& flights, const string& code) {
    for (auto& flight : flights) {
        if (flight.getFlightCode() == code) {
            return &flight;
        }
    }
    return nullptr;
}

// Hàm tìm chuyến bay theo nơi đi/nơi đến
vector<Flight> findFlightsByPlace(const vector<Flight>& flights, const string& place, bool searchByDeparture) {
    vector<Flight> result;
    for (const auto& flight : flights) {
        if ((searchByDeparture && flight.getDeparture() == place) || (!searchByDeparture && flight.getDestination() == place)) {
            result.push_back(flight);
        }
    }
    return result;
}

// Hàm đếm số chuyến bay từ nơi đi đến nơi đến
int countFlights(const vector<Flight>& flights, const string& from, const string& to) {
    int count = 0;
    for (const auto& flight : flights) {
        if (flight.getDeparture() == from && flight.getDestination() == to) {
            count++;
        }
    }
    return count;
}

// Hàm hiển thị danh sách chuyến bay
void displayFlights(const vector<Flight>& flights) {
    for (const auto& flight : flights) {
        flight.displayFlight();
    }
}

// Hàm sắp xếp danh sách chuyến bay theo ngày giờ khởi hành
void sortFlights(vector<Flight>& flights) {
    sort(flights.begin(), flights.end());
}

int main() {
    vector<Flight> flights;
    int n;

    // Nhập danh sách chuyến bay
    cout << "Nhap so luong chuyen bay: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin chuyen bay thu " << i + 1 << endl;
        Flight flight;
        flight.inputFlight();
        flights.push_back(flight);
    }

    // Sắp xếp danh sách chuyến bay
    sortFlights(flights);
    cout << "\nDanh sach cac chuyen bay da sap xep:\n";
    displayFlights(flights);

    // Tìm kiếm chuyến bay theo mã chuyến bay
    string code;
    cout << "\nNhap ma chuyen bay de tim kiem: ";
    cin >> code;
    Flight* foundFlight = findFlightByCode(flights, code);
    if (foundFlight) {
        cout << "Thong tin chuyen bay tim thay:\n";
        foundFlight->displayFlight();
    } else {
        cout << "Khong tim thay chuyen bay voi ma " << code << endl;
    }

    // Đếm số chuyến bay từ nơi đi đến nơi đến
    string from, to;
    cout << "\nNhap noi di va noi den de dem so chuyen bay: ";
    cin.ignore();
    getline(cin, from);
    getline(cin, to);
    int flightCount = countFlights(flights, from, to);
    cout << "So luong chuyen bay tu " << from << " den " << to << " la: " << flightCount << endl;

    return 0;
}
