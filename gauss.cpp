#include <time.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    srand(time(0));
    int n, i, j, k;
    n = 4;
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
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            check[i][j] = m[i][j];
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    
    /*прямой ход*/
    for (i = 0; i < n; i++)  //преобразование матрицы в треугольную
    {
        for (j = i + 1; j < n; j++)
        {
            tmp = m[j][i] / m[i][i];
            for (k = 0; k < n + 1; k++)
                m[j][k] -= m[i][k] * tmp;
        }
    }
    /*обратный ход*/
    result[n - 1] = m[n - 1][n] / m[n - 1][n - 1]; 
    for (i = n - 2; i > -1; i--) {
        result[i] = m[i][n];
        for (j = i + 1; j < n; j++)
            result[i] -= m[i][j] * result[j];
        result[i] /= m[i][i];
    }

    
    /*вывод решения*/
    cout << "---------------" << endl;
    for (i = 0; i < n; i++)
        cout << i + 1 << " " << result[i] << endl;
    
    cout << "check:" << endl;
    /*проверка*/
    for (i = 0; i < n; i++) {
        summ = 0;
        for (j = 0; j < n; j++)
            summ += check[i][j] * result[j];
        if (fabs(summ - check[i][n]) < 1e-6)
            cout << summ << " +" << endl;
        else
            cout << summ << " Miss" << endl;
    }
    return 0;
}
