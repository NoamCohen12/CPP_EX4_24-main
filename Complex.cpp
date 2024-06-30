#include "Complex.hpp"

bool Complex::operator<(const Complex& other) {
    return sqrt(real * real + image * image) < sqrt(other.real * other.real + other.image * other.image);
}

double Complex::get_real() const {
    return real;
}  // Accessor uses renamed variable
double Complex::get_imag() const {
    return image;
}  // Accessor uses renamed variable
Complex& Complex::operator+=(Complex z) {
    real += z.real;
    image += z.image;
    return *this;
}  
Complex& Complex::operator-=(Complex z) {
    real -= z.real;
    image -= z.image;
    return *this;
}
bool Complex::operator==(Complex z) const {
    return real == z.real && image == z.image;
}

bool Complex::operator!=(Complex z) const {
    return real != z.real || image != z.image;
}
ostream& operator<<(ostream& os, const Complex& c) {
    os << "(" << c.get_real() << " + " << c.get_imag() << "i)";
    return os;
}
