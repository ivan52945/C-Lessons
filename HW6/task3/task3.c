#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1 || *pa < 1) {
        printf("Error: invalid input, expected any integer a > 0\n");
        abort();
    }
}

unsigned long long pow_2_i(int i) {
    return (unsigned long long)1 << (i - 1);
}

int main() {
    int a;

    unsigned long long nSeed;

    read_input(&a);

    nSeed = pow_2_i(a);

    printf("%lld\n", nSeed);

    return 0;
}