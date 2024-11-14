#include <time.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    srand(NULL); //если не меняются рандомные числа можно написать srand(time(0))
    double a;
    int n, i, j;
    n = 10;
    double* x;  //указатель на массив
    x = new double[n]; //выделение памяти на динамический массив;
    for (i = 0; i < n; i++)
        x[i] = rand() * 1.0 / RAND_MAX; //генерация массива из случайных чисел в диапазоне от 0 до 1
    for (i = 0; i < n; i++)
        cout << x[i] << " "; //вывод массива
    cout << endl;
    for (i = 0; i < n; i++) 
        for (j = 0; j < n - 1; j++)
            if (x[j] > x[j + 1]) { //если текущий элемент массива больше следующего, то они меняются местами
                a = x[j];
                x[j] = x[j + 1];
                x[j + 1] = a;
            }
    for (i = 0; i < n; i++)
        cout << x[i] << " "; //вывод отсортированного массива     
    delete x; //очистка памяти
}
