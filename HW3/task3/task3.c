#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2) {
        printf("Error: invalid input, expected any 2 integer numbers\n");
        abort();
    }
}


int main() {
    long dif;
    int a, b;

    read_input(&a, &b);

    dif = a - b;

    printf("%ld", dif);
}