#include <omp.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
  omp_set_num_threads(4); //выделение ядер на параллельное программирование
#pragma omp parallel //запуск параллельного программирования
  {
    int i = omp_get_thread_num(); //получение номера текущего потока(ядра)
    printf("Hello world from %d \n", i); //вывод Hello world с номером текущего ядра, %d - целое число, на место которого подставляется i
}
}
