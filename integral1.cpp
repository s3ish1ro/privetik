//
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
//задание функции y = sin(x)
double f(double x) {
    return sin(x);
}


int main() {
    double Pi = 3.141592;
    double a, b, h, x_i, S;
    int n = 1000;
    a = 0;
    b = Pi / 2;
    S = 0;
    h = (b - a) / n; //вычисление шага
    for (int i = 0; i <= n; i++) {
        x_i = a + h * i; 
        S += f(x_i) * h; //вычисление интеграла по формуле
    }
    cout << S;
    return 0;

}
