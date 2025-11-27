#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 100
#define A 1.0 
#define B 3.0 
#define M_PI 3.14159265358979323846

double f(double x) {
    return x * x - cos(M_PI * x) * cos(M_PI * x);
}

int main() {
    setlocale(LC_ALL, "RUS");
    double a[N]; 
    double sum_p = 0.0; 
    double sum_n = 0.0; 
    int cnt_p = 0; 
    int cnt_n = 0; 
    double avg_p = 0.0; 
    int i;
    double step;

    step = (B - A) / (N - 1);

    for (i = 0; i < N; i++) {
        double x = A + i * step; 
        a[i] = f(x);
    }

    for (i = 0; i < N; i++) {
        if (a[i] > 0) {
            sum_p += a[i];
            cnt_p++;
        }
        else if (a[i] < 0) {
            sum_n += a[i];
            cnt_n++;
        }
    }

    if (cnt_p > 0) {
        avg_p = sum_p / cnt_p;
    }


    printf("\nИмя массива - %s", "a;");
    printf("\nСумма положительных = %.4f;", sum_p);
    printf("\nСумма отрицательных = %.4f;", sum_n);
    printf("\nЧисло положительных элементов = %d;", cnt_p);
    printf("\nЧисло отрицательных элементов = %d;", cnt_n);
    printf("\nСреднее значение = %.4f", avg_p); 


    return 0;
}