#include <time.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    srand(NULL); //если не меняются рандомные числа можно написать srand(time(0))
    double max_x, min_x, a;
    int n, i;
    n = 10;
    double* x;  //указатель на массив
    x = new double[n]; //выделение памяти на динамический массив;
    for (i = 0; i < n; i++)
        x[i] = rand() * 1.0 / RAND_MAX; //генерация массива из случайных чисел в диапазоне от 0 до 1
    for (i = 0; i < n; i++)
        cout << x[i] << " "; //вывод массива
    cout << endl;
    min_x = max_x = x[0]; //изначально максимальный и минимальный член массива - первый
    for (i = 0; i < n; i++) {
        if (x[i] < min_x) //если текущий член массива меньше минимального, то он становится минимальным
            min_x = x[i];
        if (x[i] > max_x) //по аналогии с минимумом
            max_x = x[i];
    }
    cout << min_x << " " << max_x;
    delete x; //очистка памяти
}
