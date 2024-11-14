#include <time.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    srand(NULL); //если не меняются рандомные числа можно написать srand(time(0))
    double summ = 0;
    int n, i;
    n = 10;
    double* m; //создание указателей
    double* k;
    m = new double[n]; //выделение памяти на динамический массивы
    k = new double[n];
    for (i = 0; i < n; i++)
        m[i] = rand() * 1.0 / RAND_MAX; //генерация массивов со случайными числами от 0 до 1
    for (i = 0; i < n; i++)
        k[i] = rand() * 1.0 / RAND_MAX;
    for(i = 0; i < n; i++)
        summ += m[i] * k[i]; //вычисление скалярного произведения двух векторов(суммирование произведений соответствующих элементов массивов)
    
    cout << summ;
}
