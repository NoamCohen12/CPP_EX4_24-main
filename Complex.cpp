#include "Complex.hpp" 

bool Complex::operator<(const Complex &other) {
    return sqrt(real * real + image * image) < sqrt(other.real * other.real + other.image * other.image);
}
 // to_string function
    string Complex::to_string() const {
        ostringstream oss;
        oss << "(" << real << " + " << image << "i)";
        return oss.str();
    }