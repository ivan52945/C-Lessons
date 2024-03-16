#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2) {
        printf("Error: invalid input, expected any 2 integers\n");
        abort();
    }
}

int recurs_power(int n, int p) {
    if(p > 1)
        return n * recurs_power(n, p - 1);
    else
        return n;
}

int main() {
    int a, b, pow_out;

    read_input(&a, &b);

    pow_out = recurs_power(a, b);

    printf("%d", pow_out);

    return 0;
}