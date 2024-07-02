#include <iostream>
#include <sstream>

class Complex
{
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    double get_real() const { return real; }
    double get_imaginary() const { return imaginary; }

    bool operator==(const Complex &other) const
    {
        return real == other.real && imaginary == other.imaginary;
    }

    friend std::ostream &operator<<(std::ostream &os, const Complex &c)
    {
        os << "(" << c.real << ", " << c.imaginary << ")";
        return os;
    }

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    std::string to_string() const
    {
        std::ostringstream oss;
        oss << "(" << real << ", " << imaginary << ")";
        return oss.str();
    }
};
