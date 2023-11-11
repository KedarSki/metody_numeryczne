#include <iostream>
#include <math.h>

using namespace std;

double X[] = { -1.5, -1, 0, 1, 3, 6 };
double Y[] = { -1, 0, 1, 1.58, 2.32, 3 };
int n = 5;

double fun(double x) {
    return log(x + 2) / log(2);
}

double lagrange(double xp) {
    double yp = 0;
    
    for (int i = 1; i <= n; i++) {
        double p = 1;
        
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                p = p * (xp - X[j]) / (X[i] - X[j]);
            }
        }
        
        yp = yp + p * Y[i];
    }
    
    return yp;
}


int main() {
    for (double x = -1.5; x <= 6.1; x += 0.5) {
        cout << "x: " << x 
          << ", wartosc obliczona: " << lagrange(x) 
          << ", wartosc dokladna: " << fun(x) << endl;
    }
    
    return 0;
}
