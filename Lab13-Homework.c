#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    char s[100];
    int i = 0;
    int n = 1;

    printf("¬ведите строку: ");
    gets(s);

    printf("—лова с большой буквы: ");

    while (s[i] != '\0') {
        if (n) {
            unsigned char c = s[i];
           
            if ((c >= 'A' && c <= 'Z') || (c >= 192 && c <= 223)) {
      
                while (s[i] != ' ' && s[i] != '\0') {
                    printf("%c", s[i]);
                    i++;
                }
                printf(" ");
            }
            n = 0;
        }

        if (s[i] == ' ') {
            n = 1;
        }
        i++;
    }

    printf("\n");
    return 0;
}