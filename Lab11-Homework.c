#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int n, i, min_i = 0, proizv = 1;

    printf("Введите количество элементов (не более 100): ");
    scanf("%d", &n);

    int mas[100]; 

    printf("Введите элементы массива:\n");
    for (i = 0; i < n; i++) {
        printf("mas[%d] = ", i);
        scanf("%d", &mas[i]);
    }

    for (i = 1; i < n; i++) {
        if (mas[i] < mas[min_i]) {
            min_i = i;
        }
    }

    printf("\nМинимальный элемент: %d (индекс %d)\n", mas[min_i], min_i);


    if (min_i < n - 1) {
        for (i = min_i + 1; i < n; i++) {
            proizv *= mas[i];
        }
        printf("Произведение элементов после минимального: %d\n", proizv);
    }
    else {
        printf("После минимального элемента нет других элементов\n");
    }

    return 0;
}