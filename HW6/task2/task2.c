#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1 || *pa < 2) {
        printf("Error: invalid input, expected any integer a > 1\n");
        abort();
    }
}

long arifm_progr(int n) {
    return (1 + n) * (n) / 2;
}

int main() {
    int a;
    long progr;

    read_input(&a);

    progr = arifm_progr(a);

    printf("%ld\n", progr);

    return 0;
}