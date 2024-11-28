#include <omp.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    srand(NULL);
    omp_set_num_threads(4);
    int i, n, j, k;
    n = 1000;
    double** m; 
    double** l;
    double** result;
    m = new double* [n]; 
    l = new double* [n];
    result = new double* [n];
    
    for (i = 0; i < n; i++)
        m[i] = new double[n]; 
    for (i = 0; i < n; i++)
        l[i] = new double[n];
    for (i = 0; i < n; i++)
        result[i] = new double[n];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            m[i][j] = rand() * 1.0 / RAND_MAX;
            /*if (j < i)
                m[i][j] = 0;
            else
                m[i][j] = rand() * 1.0 / RAND_MAX;*/ //генерация треугольной матрицы

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            l[i][j] = rand() * 1.0 / RAND_MAX;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = 0; 
    double t1 = omp_get_wtime();
#pragma omp parallel for private(j, k) //private(j, k) означает что j, k для каждого потока свои
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                result[i][j] += m[i][k] * l[k][j]; //произведение матриц
    
    double t2 = omp_get_wtime();
    cout << "time " << t2 - t1 << endl;
}
