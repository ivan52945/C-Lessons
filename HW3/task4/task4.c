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
    int a, b, c;
    double average;

    read_input(&a, &b, &c);

    average = (a + b + c) / 3.0;

    printf("%lf", average);
}