#include <cstdio>
#include <omp.h>
#include <string>
#include <iostream>

int firstTask();
int secondTask();
void thirdTask();
int fourthTask();
void fifthTask();

int firstTask() {
    int n = 1;
    printf("n последовательной области (начало): %d\n",n);
#pragma omp parallel default(none) private(n) num_threads(4)
    {
        printf("n последовательной области (на входе): %d\n",n);
        n = omp_get_thread_num();
        printf("n последовательной области (на выходе): %d\n",n);
    }
    printf("n последовательной области (конец): %d\n",n);
    printf("--------------конец первой задачи-------------\n");
}

int secondTask() {
    std::string hw = "Hello world\n";
#pragma omp parallel shared(hw)
    std::cout << hw;
    printf("----------конец второй задачи--------------\n");
    return 0;
}

void thirdTask() {
#pragma omp for
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 2; j++)
        {
            std::cout << i << " ";
            std::cout << j << " ";
        }
    printf("\n");
    printf("----------конец 3 задачи--------------\n");
}

int fourthTask() {
    int x = 0;
#pragma omp parallel default(none) shared(x) num_threads(100)
    {
        x += 1;
    }
    std::cout << "x = " << x << std::endl;
    printf("----------конец четвертой задачи--------------\n");
    return 0;
}

void fifthTask() {
    std::cout << omp_get_num_procs;
    int a[100], b[100], c[100], d[100];
#pragma omp parallel for
    for(int i = 0; i < 100; i++) {
        a[i] = i;
        b[i] = i;
        d[i] = 2 * i;
        std::cout << omp_get_thread_num();
        std::cout << omp_get_num_threads;

    }
#pragma omp parallel for
    for(int i = 0; i < 100; i++) {
        c[i] = a[i] + b[i] + d[i];
    }
    std::cout << a[50] << "\n";
    printf("----------конец пятой задачи--------------\n");
}
