#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any 1 integer\n");
        abort();
    }
}

void reverse(int a) {
    printf("%d ", a % 10);

    if(a > 9)
        reverse(a / 10);
}


int main() {
    int a;

    read_input(&a);

    reverse(a);

    printf("\n");

    return 0;
}