#include <omp.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    srand(NULL);
    omp_set_num_threads(4);
    int i, n;
    n = 50000000;
    double* m; double* l; double* result;
    m = new double [n]; 
    l = new double [n];
    result = new double [n];
    
    for (i = 0; i < n; i++)
        m[i] = rand() * 1.0/RAND_MAX; 
    for (i = 0; i < n; i++)
        l[i] = rand() * 1.0/RAND_MAX;
    for (i = 0; i < n; i++)
        result[i] = 0;
    double t1 = omp_get_wtime(); // получение времени до начала выполнения параллельного программирования
#pragma omp parallel for //распараллеливание цикла for
    for(i = 0; i < n; i++)
        result[i] += m[i] + l[i]; //сумма соответствующих членов двух векторов(сумма векторов)
    double t2 = omp_get_wtime(); // получение времени после завершения
    cout << "Time: " << t2 - t1; //вывод времени программы(конец - начало)
