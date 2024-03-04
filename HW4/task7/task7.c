#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb, int* pc, int* pd, int* pe) {
    int n_items = 0;

    n_items = scanf("%d%d%d%d%d", pa, pb, pc, pd, pe);
    if(n_items != 5) {
        printf("Error: invalid input, expected any 5 integer numbers\n");
        abort();
    }
}

int main() {
    int a, b, c, d, e, max;

    read_input(&a, &b, &c, &d, &e);

    max = a;
    max = b > max ? b : max;
    max = c > max ? c : max;
    max = d > max ? d : max;
    max = e > max ? e : max;

    printf("%d\n", max);

    return 0;
}