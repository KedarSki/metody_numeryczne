#include <iostream>

using namespace std;

double X[] = { -1, 0, 1, 2 };
double Y[] = { -3, 0, 1, 3 };
int n = 4;

int main() {
    double sx = 0, sy = 0, sx2 = 0, sxy = 0;
    
    for (int i = 0; i < n; i++) {
        sx += X[i];
        sy += Y[i];
        sx2 += X[i] * X[i];
        sxy += X[i] * Y[i];
    }
    
    double a = (n * sxy - sx * sy) / (n * sx2 - sx * sx);
    double b = (sy * sx2 - sx * sxy) / (n * sx2 - sx * sx);
    
    cout << "funkcja: " << a << " * x + " << b << endl;
    
    for (double x = -1; x <= 3.1; x += 0.2) {
        double y = a * x + b;
        cout << "x: " << x << ", wartosc obliczona: " << y << endl;
    }
    
    return 0;
}
