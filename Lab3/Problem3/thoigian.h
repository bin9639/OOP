
// thoigian.h
#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>
using namespace std;

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay);

    // Phương thức
    int TinhGiay() const;
    void TinhLaiGio(int Giay);

    // Toán tử
    ThoiGian operator+(int Giay) const;
    ThoiGian operator-(int Giay) const;
    ThoiGian operator+(const ThoiGian& a) const;
    ThoiGian operator-(const ThoiGian& a) const;

    ThoiGian& operator++();        // tiền tố ++
    ThoiGian operator++(int);      // hậu tố ++
    ThoiGian& operator--();        // tiền tố --
    ThoiGian operator--(int);      // hậu tố --

    bool operator==(const ThoiGian& other) const;
    bool operator!=(const ThoiGian& other) const;
    bool operator<(const ThoiGian& other) const;
    bool operator>(const ThoiGian& other) const;
    bool operator<=(const ThoiGian& other) const;
    bool operator>=(const ThoiGian& other) const;

    friend istream& operator>>(istream& in, ThoiGian& tg);
    friend ostream& operator<<(ostream& out, const ThoiGian& tg);
};

#endif // THOIGIAN_H

// thoigian.h
#ifndef THOIGIAN_H
#define THOIGIAN_H

#include <iostream>
using namespace std;

class ThoiGian {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    ThoiGian();
    ThoiGian(int Gio, int Phut, int Giay);

    // Phương thức
    int TinhGiay() const;
    void TinhLaiGio(int Giay);

    // Toán tử
    ThoiGian operator+(int Giay) const;
    ThoiGian operator-(int Giay) const;
    ThoiGian operator+(const ThoiGian& a) const;
    ThoiGian operator-(const ThoiGian& a) const;

    ThoiGian& operator++();        // tiền tố ++
    ThoiGian operator++(int);      // hậu tố ++
    ThoiGian& operator--();        // tiền tố --
    ThoiGian operator--(int);      // hậu tố --

    bool operator==(const ThoiGian& other) const;
    bool operator!=(const ThoiGian& other) const;
    bool operator<(const ThoiGian& other) const;
    bool operator>(const ThoiGian& other) const;
    bool operator<=(const ThoiGian& other) const;
    bool operator>=(const ThoiGian& other) const;

    friend istream& operator>>(istream& in, ThoiGian& tg);
    friend ostream& operator<<(ostream& out, const ThoiGian& tg);
};

#endif // THOIGIAN_H
