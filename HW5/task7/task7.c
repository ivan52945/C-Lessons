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
    int a;
    int reversedA = 0;

    read_input(&a);
    if(a > 9) {
        while(a > 0) {
            reversedA = reversedA * 10 + (a % 10);

            a /= 10;
        }
    }
    else {
        reversedA = a;
    }

    printf("%d\n", reversedA);

    return 0;
}