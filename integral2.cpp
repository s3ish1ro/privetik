#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double f(double x) {
    return sin(x);
}


int main() {
    double Pi = 3.141592;
    double a, b, h, x_i, S_n, s;
    double eps = 1.0e-7;
    int n = 2;
    int i = 0;
    a = 0;
    b = Pi / 2;
    s = f(a) * (b - a) + f(b) * (b - a); //вычисление интеграла при n = 1
    while (true) {
        S_n = 0;
        h = (b - a) / n;  //текущий шаг
        for (i = 0; i <= n; i++) {
            x_i = a + i * h;      //вычисление по формуле при текущем n
            S_n += f(x_i) * h;
        }
        n++;
        if (abs(S_n - s) < eps) { //остановка цикла
            break;
        }
        s = S_n;

    }
    cout << S_n << " " << n;
}
