#include <time.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    srand(time(0));
    int n, i, j, k;
    n = 3;
    double summ;
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
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            check[i][j] = m[i][j];
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    double tmp;
    /*прямой ход*/
    for (i = 0; i < n; i++)
    {
        tmp = m[i][i];
        for (j = n; j >= i; j--)
            m[i][j] /= tmp;
        for (j = i + 1; j < n; j++)
        {
            tmp = m[j][i];
            for (k = n; k >= i; k--)
                m[j][k] -= tmp * m[i][k];
        }
    }
    /*обратный ход*/
    result[n - 1] = m[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        result[i] = m[i][n];
        for (j = i + 1; j < n; j++) result[i] -= m[i][j] * result[j];
    }
    /*вывод решения*/
    cout << "---------------" << endl;
    for (i = 0; i < n; i++)
        cout << i + 1 << " " << result[i] << endl;
    /*проверка*/
    for (i = 0; i < n; i++) {
        summ = 0;
        for (j = 0; j < n; j++)
            summ += check[i][j] * result[j];
        cout << summ << endl;
    }
    return 0;
}
