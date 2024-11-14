#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

int main() {
    srand(time(0));
    int n, i, j, l; 
    n = 10;
    double** m; //создание указателя на указатель
    double** k;
    double** result;
    m = new double* [n]; //массив из указателей для генерации двумерного массива(матрицы)
    k = new double* [n];
    result = new double* [n];

    for (i = 0; i < n; i++)
        m[i] = new double[n]; //выделение памати для динамического массива в каждом указателе массива указателей(для матрицы)
    for (i = 0; i < n; i++)
        k[i] = new double[n];
    for (i = 0; i < n; i++)
        result[i] = new double[n];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            m[i][j] = rand() * 1.0 / RAND_MAX; //генерация матрицы случайных чисел от 0 до 1
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            k[i][j] = rand() * 1.0 / RAND_MAX;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = 0; //генерация нулевой матрицы, в которой будет считаться результат

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (l = 0; l < n; l++)
                result[i][j] += m[i][l] * k[l][j]; //происходит проход по строкам(i) и столбцам(j), l - общий индекс двух массивов для суммы всех произведений
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << result[i][j] << " "; //вывод полученной матрицы
        cout << endl;
    }
    for (i = 0; i < n; i++){ //очистка памяти каждого указателя в массиве указателей
        delete m[i];
        delete k[i];
        delete result[i];
    }
    delete m; //очистка указателей на указатели
    delete k;
    delete result;
}
