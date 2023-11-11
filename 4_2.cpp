#include <iostream>
#include <math.h>

using namespace std;

double fun(double x) {
    return sin(x) - 0.5 * x;
}

double secant(double a, double b, double eps) {
    double fa = fun(a);
    double fb = fun(b);
    
    
    cout << "Metoda siecznych dla x = " << b << " fx = " << fb << endl;
    
    if (abs(fb) < eps) {
        return b;
    }
    
    double c = (fb * a - fa * b) / (fb - fa);
    
    return secant(b, c, eps);
}

int main() {
    double x0 = secant(M_PI / 2, M_PI, 0.001);
    cout << "Znaleziono miejsce zerowe w x = " << x0 << endl;
    return 0;
}
