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
    int a, b, c, d, e, max, min, sum;

    read_input(&a, &b, &c, &d, &e);

    max = a;
    max = b > max ? b : max;
    max = c > max ? c : max;
    max = d > max ? d : max;
    max = e > max ? e : max;

    min = a;
    min = b < min ? b : min;
    min = c < min ? c : min;
    min = d < min ? d : min;
    min = e < min ? e : min;

    sum = max + min;

    printf("%d\n", sum);

    return 0;
}