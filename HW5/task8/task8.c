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

int main() {
    int a, digit;
    int max = 0, min = 9;

    read_input(&a);

    if(a > 9) {
        while(a > 0) {
            digit = a % 10;

            max = (digit > max) ? digit : max;
            min = (digit < min) ? digit : min;

            a /= 10;
        }
    }
    else {
        min = a;
        max = a;
    }

    printf("%d %d\n", min, max);

    return 0;
}