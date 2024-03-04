#include <stdio.h>
#include <stdlib.h>

void read_input(unsigned int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1 || (*pa) < 100 || (*pa > 999)) {
        printf("Error: invalid input, expected any integer > 99 and < 1000\n");
        abort();
    }
}


int main() {
    unsigned int a;
    unsigned int digitMult = 1;

    read_input(&a);

    digitMult *= a % 10;
    a /= 10;
    digitMult *= a % 10;
    a /= 10;
    digitMult *= a;

    printf("%d\n", digitMult);
}