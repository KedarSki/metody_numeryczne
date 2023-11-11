#include <iostream>
#include <math.h>

using namespace std;

double fun(double x) {
    return 1 / (cos(x) * cos(x));
}

double simpson(double start, double end, int n) {
    double integral = 0, st = 0;
    double dx = (end - start) / n;
    
    for (int i = 1; i <= n; i++) {
        double x = start + i * dx;
        st += fun(x - dx / 2);
        
        if (i < n) {
            integral += fun(x);
        }
    }
    
    integral = dx / 6 * (fun(start) + fun(end) + 2 * integral + 4 * st);
    
    return integral;
}

int main() {
    double expected = 1.55740772465;
    
    double start = 0;
    double end = 1;
    double eps = 0.00001;
    
    int n = 1;
    int nStep = 1;
    double error = eps;
    double integral = 0;
    
    while (error >= eps) {
        n += nStep;
        integral = simpson(start, end, n);
        error = abs(integral - expected);
    }
    
    cout << "Wartosc calki oznaczonej dla metody simpsona: " << integral << endl;
    cout << "Wymagana liczba przedzialow: " << n + 1 << endl;
    cout << "Blad absolutny dla metody simpsona: " << abs(integral - expected) << endl;
    
    return 0;
}
