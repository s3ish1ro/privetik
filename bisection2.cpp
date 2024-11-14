#include <iostream>
#include <math.h>
#include <stdio.h>
#include <time.h>
using namespace std;

double f(double x) {
    return sin(x);
}

int main() {
    double a, b, middle, eps, i;
    double left, right, step;
    eps = 1e-5;
    step = 0.1; 
    left = -10;
    right = 10;
    for (i = left; i <= right - step; i += step) {
        a = i;
        b = i + step;
        if (f(a) == 0)
            cout << a << endl;
        else {
            if (f(b) * f(a) < 0) {
                while (fabs(a - b) > eps) {
                    middle = (b + a) / 2;
                    if (f(middle) * f(b) < 0)
                        a = middle;
                    else
                        b = middle;
                }
                cout << a << endl;
            }
        }
    }
    return 0;
}
