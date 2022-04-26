#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double _real = 0, _imag = 0;

public:
    Complex(double real, double im) {
        this->_real = real;
        this->_imag = im;
    }

    Complex()
            : Complex(0,0) {

    }

    Complex(const Complex &rhs)
            : Complex(rhs._real, rhs._imag) {
    }

    Complex(const Complex &&rhs)
            : Complex(rhs._real, rhs._imag) {
    }

    void print() { cout << _real << " " << _imag << "*i\n"; }
    double real() const { return _real; }
    double imag() const { return _imag; }
    double abs() const { return sqrt(_real*_real + _imag*_imag); }
    Complex conjugate() const { return Complex(_real, -_imag); }
    Complex inverse() const { return conjugate()/(real()*real()+imag()*imag()); }

    Complex& operator=(const Complex&);
    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator*=(const double&);
    Complex& operator/=(const Complex&);
    Complex& operator/=(const double&);

    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const double&);
    friend Complex operator*(const double&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const double&);
    friend Complex operator/(const double&, const Complex&);
    friend Complex operator-(const Complex&);
    friend Complex operator+(const Complex&);
};

Complex operator+(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs)+=rhs;
}

Complex operator-(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs)-=rhs;
}

Complex operator*(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs)*=rhs;
}

Complex operator*(const Complex &lhs, const double &rhs) {
    return Complex(lhs)*=rhs;
}

Complex operator*(const double &lhs, const Complex &rhs) {
    return Complex(rhs)*=lhs;
}

Complex operator/(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs)/=rhs;
}

Complex operator/(const Complex &lhs, const double &rhs) {
    return Complex(lhs)/=rhs;
}

Complex operator/(const double &lhs, const Complex &rhs) {
    return lhs*rhs.inverse();
}

Complex operator-(const Complex &lhs) {
    return Complex(-lhs._real, -lhs._imag);
}

Complex operator+(const Complex &lhs) {
    return lhs;
}

Complex& Complex::operator=(const Complex &rhs) {
    this->_real =rhs._real;
    this->_imag = rhs._imag;
    return *this;
}

Complex& Complex::operator+=(const Complex &rhs) {
    this->_real += rhs._real;
    this->_imag += rhs._imag;
    return *this;
}

Complex& Complex::operator-=(const Complex &rhs) {
    *this += -rhs;
    return *this;
}
// (a+bi)(c+di) = ac-bd + i(ad+bc)
Complex& Complex::operator*=(const Complex &rhs) {
    double real = this->_real, imag = this->_imag;
    this->_real = real*rhs._real - imag*rhs._imag;
    this->_imag = imag*rhs._real + real*rhs._imag;
    return *this;
}

Complex& Complex::operator*=(const double &rhs) {
    this->_real *= rhs;
    this->_imag *= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex &rhs) {
    *this *= rhs.inverse();
    return *this;
}

Complex& Complex::operator/=(const double &rhs) {
    this->_real /= rhs;
    this->_imag /= rhs;
    return *this;
}


int main() {
    Complex z1 = Complex(3,1);
    Complex z2 = Complex(5,-2);
    (z1+z2).print();
    (z1-z2).print();
    (z1*z2).print();
    (1/z2).print(); // z2.inverse().print();
    (z1/z2).print();
    return 0;
}