#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected only integer numbers\n");
        abort();
    }
}

void prnt_not_even(void) {
    int a;

    read_input(&a);

    if((a % 2) != 0)
        printf("%d ", a);

    if(a != 0)
        prnt_not_even();

}

int main() {
    prnt_not_even();

    return 0;
}