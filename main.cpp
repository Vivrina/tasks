#include <iostream>
#include <omp.h>
#include <time.h>
#include <chrono>
#include <synchapi.h>

using namespace std;

//Задание 12
void numberTwelve() {
    int n = 100;
    int a[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d\n", a[i]);
    }

    int max = -1;
    #pragma omp parallel
    {
    #pragma omp for schedule(auto)
        for (int i = 0; i < n; i++) {
            printf("Thread %d\n",omp_get_thread_num());
            if (a[i] % 7 == 0) {
    #pragma omp critical
                    if (a[i] > max) {
                        max = a[i];
                    }

            }
        }
    }
    printf("Max: %d\n", max);
}

void numberThirteen() {
#pragma omp parallel num_threads(8)
    {
        Sleep((omp_get_num_threads() - omp_get_thread_num()) * 100);
        printf("#%d of %d - Hello World\n", omp_get_thread_num(), omp_get_num_threads());
    }
    printf("\n");
}




int main() {
    //Задание 12 (запуск)
    numberTwelve();

    printf("_____________________________________________________________________________\n");
    printf("_____________________________________________________________________________\n");


    //Задание 13 - 1 вариант (запуск)
    numberThirteen();

}
