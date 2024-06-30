#ifndef COMPLEX_HPP
#define COMPLEX_HPP

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
    double get_real() const ;
    double get_imag() const ;
    Complex& operator+=(Complex z);
    Complex& operator-=(Complex z);
    bool operator==(Complex z) const;
    bool operator!=(Complex z) const;
    bool operator<(const Complex &other);
   

    friend ostream& operator<<(ostream& os, const Complex& c);


   


};
#endif // COMPLEX_HPP