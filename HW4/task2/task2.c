#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb, int* pc) {
    int n_items = 0;

    n_items = scanf("%d%d%d", pa, pb, pc);
    if(n_items != 3) {
        printf("Error: invalid input, expected any 5 integer numbers\n");
        abort();
    }
}

int main() {
    int a, b, c, max;

    read_input(&a, &b, &c);

    max = a;
    max = b > max ? b : max;
    max = c > max ? c : max;

    printf("%d\n", max);

    return 0;
}