#include <string>
#include <cmath> 
#include <sstream>

using namespace std;
class Complex{
    private:
    double real, image; // Renamed variables
public:
    Complex(double r, double i) : real(r), image(i) {}
    Complex(double r) : real(r), image(0) {}
    Complex() : real(0), image(0) {}
    double get_real() const { return real; } // Accessor uses renamed variable
    double get_imag() const { return image; } // Accessor uses renamed variable
    Complex& operator+=(Complex z) { real+=z.real; image+=z.image; return *this; } // Use renamed variables
    Complex& operator-=(Complex z) { real-=z.real; image-=z.image; return *this; } // Use renamed variables
    bool operator==(Complex z) const { return real==z.real && image==z.image; }; // Use renamed variables
    bool operator!=(Complex z) const { return real!=z.real || image!=z.image; }; // Use renamed variables
    bool operator <(const Complex &other);
    string to_string() const;

};
