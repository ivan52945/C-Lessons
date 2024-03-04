#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any 5 integer numbers\n");
        abort();
    }
}

int main() {
    int a, digit, max;

    read_input(&a);

    digit = a % 10;
    max = digit;
    a = a / 10;

    digit = a % 10;
    max = digit > max ? digit : max;
    a = a / 10;

    digit = a;
    max = digit > max ? digit : max;

    printf("%d\n", max);

    return 0;
}