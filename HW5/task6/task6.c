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
    int a, digit;;
    int areEven = 1;

    read_input(&a);

    while(a > 0) {
        digit = a % 10;

        if((digit % 2) != 0) {
            areEven = 0;
            break;
        }

        a /= 10;
    }

    if(areEven)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}