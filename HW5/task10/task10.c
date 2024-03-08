#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1 || *pa < 10) {
        printf("Error: invalid input, expected any 1 integer a > 10\n");
        abort();
    }
}

int main() {
    int a, copy, digit, sum, mult;

    read_input(&a);

    for(int i = 10; i <= a; i++) {
        copy = i;

        sum = 0;
        mult = 1;

        while(copy > 0) {
            digit = copy % 10;

            if(digit != 0) {
                sum += digit;
                mult *= digit;
            }
            else {
                sum = 1;
                mult = 0;
                break;
            }

            copy /= 10;
        }

        if(sum == mult)
            printf("%d ", i);
    }

    printf("\n");

    return 0;
}