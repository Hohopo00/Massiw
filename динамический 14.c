#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double calc(double x);
double find_product_after_min(double* ptr_array, int n);

double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double find_max_in_range(double* ptr_array, int start, int end);

double calculate_between_min_max(double* ptr_array, int n, int type);

int main() {
    setlocale(LC_CTYPE, "RUS");

    double* ptr_array;
    int size;

    printf("Введите размер массива - ");
    scanf("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));

    if (ptr_array == NULL) {
        puts("Ошибка выделения памяти");
        return -1;
    }

    full_elements(ptr_array, size);

    printf("Исходный массив: \n");
    put_elements(ptr_array, size);

    printf("Обработанный массив:\n");
    calc_elements(ptr_array, size);
    put_elements(ptr_array, size);

    double product = find_product_after_min(ptr_array, size);
    printf("Произведение элементов после минимального: %.4f\n", product);

    int begin, end;
    printf("\n=== Операции с диапазоном ===\n");
    printf("Введите начало диапазона (от 1 до %d): ", size);
    scanf("%d", &begin);
    printf("Введите конец диапазона (от %d до %d): ", begin, size);
    scanf("%d", &end);

    if (begin >= 1 && end <= size && begin <= end) {
        double sum = sum_elements(ptr_array, begin - 1, end - 1);
        printf("Сумма элементов в диапазоне [%d, %d]: %.4f\n", begin, end, sum);

        double max_value = find_max_in_range(ptr_array, begin - 1, end - 1);
        printf("Максимальное значение в интервале [%d, %d]: %.4f\n", begin, end, max_value);
    }
    else {
        printf("Некорректный диапазон!\n");
    }

    double search_element;
    printf("\nВведите элемент для поиска: ");
    scanf("%lf", &search_element);
    int found_index = find_element(ptr_array, size, search_element);

    if (found_index != -1) {
        printf("Элемент %.4f найден на позиции %d\n", search_element, found_index + 1);
    }
    else {
        printf("Элемент %.4f не найден в массиве\n", search_element);
    }

    printf("\n=== ДОМАШНЕЕ ЗАДАНИЕ ===\n");
    printf("Вычислить произведение/сумму значений элементов массива\n");
    printf("находящихся между максимальным и минимальным элементами\n");

    int calculation_type;
    printf("\nВыберите тип вычисления:\n");
    printf("0 - произведение элементов\n");
    printf("1 - сумма элементов\n");
    printf("Ваш выбор: ");
    scanf("%d", &calculation_type);

    if (calculation_type == 0 || calculation_type == 1) {
        double result = calculate_between_min_max(ptr_array, size, calculation_type);

        if (calculation_type == 0) {
            printf("Произведение элементов между минимальным и максимальным: %.4f\n", result);
        }
        else {
            printf("Сумма элементов между минимальным и максимальным: %.4f\n", result);
        }
    }
    else {
        printf("Некорректный тип вычисления!\n");
    }

    free(ptr_array);

    return 0;
}

double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        double x = i + 1;
        ptr_array[i] = 3 * x + 5;
    }
    return ptr_array;
}
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] = %.4f\n", i + 1, ptr_array[i]);
    }
    printf("\n");
    return n;
}

double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = calc(ptr_array[i]);
    }

    return ptr_array;
}

double calc(double x) {
    return fabs(log10(x)) + pow(x - 2, 2);
}

double find_product_after_min(double* ptr_array, int n) {
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (ptr_array[i] < ptr_array[min_index]) {
            min_index = i;
        }
    }

    double product = 1.0;
    for (int i = min_index + 1; i < n; i++) {
        product *= ptr_array[i];
    }

    return product;
}

double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - element) < 0.0001) {
            return i;
        }
    }
    return -1;
}

double find_max_in_range(double* ptr_array, int start, int end) {
    double max_value = ptr_array[start];
    for (int i = start + 1; i <= end; i++) {
        if (ptr_array[i] > max_value) {
            max_value = ptr_array[i];
        }
    }
    return max_value;
}

double calculate_between_min_max(double* ptr_array, int n, int type) {
    if (n < 2) {
        printf("Массив слишком мал для вычисления!\n");
        return 0.0;
    }

    int min_index = 0;
    int max_index = 0;

    for (int i = 1; i < n; i++) {
        if (ptr_array[i] < ptr_array[min_index]) {
            min_index = i;
        }
        if (ptr_array[i] > ptr_array[max_index]) {
            max_index = i;
        }
    }

    printf("\nМинимальный элемент: %.4f на позиции %d\n", ptr_array[min_index], min_index + 1);
    printf("Максимальный элемент: %.4f на позиции %d\n", ptr_array[max_index], max_index + 1);

    int start_index, end_index;
    if (min_index < max_index) {
        start_index = min_index;
        end_index = max_index;
    }
    else {
        start_index = max_index;
        end_index = min_index;
    }

    if (end_index - start_index <= 1) {
        printf("Между минимальным и максимальным элементами нет других элементов\n");
        return 0.0;
    }

    double result;
    if (type == 0) { 
        result = 1.0;
        for (int i = start_index + 1; i < end_index; i++) {
            result *= ptr_array[i];
        }
    }
    else { 
        result = 0.0;
        for (int i = start_index + 1; i < end_index; i++) {
            result += ptr_array[i];
        }
    }

    printf("Количество элементов между min и max: %d\n", end_index - start_index - 1);

    return result;
}