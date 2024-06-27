#include <cmath> // Include this at the top of your Complex.cpp file

bool Complex::operator<(const Complex &other) {
    return sqrt(real * real + imag * imag) < sqrt(other.real * other.real + other.imag * other.imag);
}
 // to_string function
    std::string Complex::to_string() const {
        std::ostringstream oss;
        oss << "(" << realPart << " + " << imagePart << "i)";
        return oss.str();
    }