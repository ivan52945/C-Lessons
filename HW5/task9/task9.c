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
    int evenN = 0, notEvenN = 0;

    read_input(&a);

    while(a > 0) {
        digit = a % 10;

        if((digit % 2) != 0)
            notEvenN += 1;
        else
            evenN += 1;

        a /= 10;
    }

    printf("%d %d", evenN, notEvenN);

    return 0;
}