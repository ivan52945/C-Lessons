#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb, int* pc) {
    int n_items = 0;

    n_items = scanf("%d%d%d", pa, pb, pc);
    if(n_items != 3) {
        printf("Error: invalid input, expected any 3 integer numbers\n");
        abort();
    }
}


int main() {
    long sum;
    int a, b, c;

    read_input(&a, &b, &c);

    sum = a + b + c;

    printf("%d+%d+%d=%ld\n", a, b, c, sum);
}