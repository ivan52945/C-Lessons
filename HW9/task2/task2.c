// для проверки работоспособности всей программы нужно в строчке в #define NOTEST поставить 1 вместо 0
#define NOTEST 1

#if NOTEST

#define SIZE 40
#include <stdio.h>
#include <stdlib.h>

void print_digit(char s []);

int main() {
    char arr[SIZE];

    scanf("%[^\n]", arr);

    print_digit(arr);

    return 0;
}

#endif

void print_form(int size, int arr []) {
    for(int i = 0; i < size; i++)
        if(arr[i] > 0) {
            printf("%d %d\n", i, arr[i]);
        }

}

void count_digit(char s [], int count []) {
    for(int i = 0; s[i] != '\0';i++)
        if(s[i] - '0' >= 0 && s[i] - '0' < 10) {
            count[s[i] - '0'] += 1;
        }
}

void print_digit(char s []) {
    int count[10] = {};

    count_digit(s, count);

    print_form(10, count);
}
