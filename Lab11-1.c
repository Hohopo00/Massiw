#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define N 10  


task1() {
    setlocale(LC_ALL, "RUS");
    float A[N + 1];  
    float sum = 0.0; 
    float average;  

    printf("Введите %d чисел:\n", N);


    for (int i = 1; i <= N; i++) {
        printf("A[%d] = ", i);
        scanf("%f", &A[i]);
    }


 

    printf("| Индекс | Исходное значение | Новое значение  |\n");


    for (int i = 1; i <= N; i++) {
        float new_value = A[i];

        if (i % 2 == 0) {
            new_value = A[i] + 1.0;
        }
        printf("|   %2d   |      %8.2f     |     %8.2f     |\n",
            i, A[i], new_value);

        if (i % 2 == 0) {
            A[i] += 1.0;
        }
    }



    for (int i = 1; i <= N; i++) {
        sum += A[i];
    }

    average = sum / N;

    printf("Среднее арифметическое: %.2f\n", average);

    return 0;
}

int main() {
    task1();
}