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
    int a, b;

    read_input(&a, &b);

    if(a > b)
        printf("Above\n");
    else if(a == b)
        printf("Equal\n");
    else
        printf("Less\n");

    return 0;
}