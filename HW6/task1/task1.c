#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2) {
        printf("Error: invalid input, expected any 2 integer\n");
        abort();
    }
}

int middle(int a, int b) {
    return (a + b) / 2;
}

int main() {
    int a, b, avg;

    read_input(&a, &b);

    avg = middle(a, b);

    printf("%d\n", avg);

    return 0;
}