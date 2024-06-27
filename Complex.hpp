class complex{
    double real, image;
public:
    complex(double r, double i) : real(r), image(i) {}
    complex(double r) : real(r), image(0) {}
    complex() : real(0), image(0) {}
    double real() const { return real; }
    double imag() const { return image; }
    complex& operator+=(complex z) { real+=z.real; image+=z.image; return *this; }
    complex& operator-=(complex z) { real-=z.real; image-=z.image; return *this; }
    bool operator==(complex z) const { return real==z.real && image==z.image; };
    bool operator!=(complex z) const { return real!=z.real || image!=z.image; };
    bool operator <(complex z);

};

