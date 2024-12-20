#include <time.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <omp.h>
using namespace std;

int main() {
    srand(time(0));
    int n, i, j, k;
    n = 2000;
    double summ, tmp, s1;
    double** m;
    double* result;
    double** check;
    m = new double* [n];
    result = new double[n];
    check = new double* [n];
    for (i = 0; i < n; i++)
        m[i] = new double[n];
    for (i = 0; i < n; i++)
        check[i] = new double[n];
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            m[i][j] = rand() * 1.0 / RAND_MAX;

    
    double t1 = omp_get_wtime();
    /*прямой ход*/
    for (i = 0; i < n; i++)
    #pragma omp parallel for private(k)
        for (j = i + 1; j < n; j++)
        {
            tmp = m[j][i] / m[i][i];
            for (k = 0; k < n + 1; k++)
                m[j][k] -= m[i][k] * tmp;
        }
    double t2 = omp_get_wtime();
    cout << "time 1: " << t2 - t1 << endl;

    /*обратный ход*/
    result[n - 1] = m[n - 1][n] / m[n - 1][n - 1];
    for (i = n - 2; i > -1; i--) {
        result[i] = m[i][n];
        #pragma omp parallel for 
            for (j = i + 1; j < n; j++)
                result[i] -= m[i][j] * result[j];
        result[i] /= m[i][i];
    }
    double t3 = omp_get_wtime();
    cout << "time 2: " << t3 - t2 << endl;
    cout << "time: " << t3 - t1 << endl;
 
    return 0;
}
