#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1 || *pa < 0) {
        printf("Error: invalid input, expected any integer a >= 0\n");
        abort();
    }
}

int factorial(int n) {
    int res = 1;

    for(int i = 2; i <= n; i++) {
        res *= i;
    }

    return res;
}

int main() {
    int a, f;

    read_input(&a);

    f = factorial(a);

    printf("%d\n", f);

    return 0;
}