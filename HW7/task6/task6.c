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

int is2pow(int n) {
    if(n == 0)
        return 0;

    if((n % 2) == 0)
        return is2pow(n / 2);

    if(n == 1)
        return 1;
    else
        return 0;
}

int main() {
    int a, res;

    read_input(&a);

    res = is2pow(a);

    if(res)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}