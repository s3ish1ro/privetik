#include <iostream>
#include <math.h>
#include <stdio.h>
#include <time.h>
using namespace std;

double f(double x) {
    return sin(x);
}

int main() {
  double middle;
  double a = -1;
  double b = 5;
  double eps = 1e-5;
  while (fabs(a - b) > eps) {
    middle = (b + a) / 2;  // середина текущего отрезка
    if (f(middle) * f(b) < 0) //проверка на различие знаков середины и концов отрезка
      a = middle; //замена конца отрезка
    else
      b = middle;
  }
  cout << a << endl;
