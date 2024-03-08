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
    int oneDigitNine = 0;

    read_input(&a);

    while(a > 0) {
        if(a % 10 == 9)
            oneDigitNine += 1;
        if(oneDigitNine > 1)
            break;

        a /= 10;
    }

    if(oneDigitNine != 1)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}