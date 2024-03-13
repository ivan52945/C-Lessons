#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2) {
        printf("Error: invalid input, expected any 2 integer\n");
        abort();
    }
}

int nod(int a, int b) {

    long long tmp = 0;

    while(b != 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return a < 0 ? -a : a;
}



int main() {
    int a, b, gcd_out;

    read_input(&a, &b);

    gcd_out = nod(a, b);

    printf("%d\n", gcd_out);

    return 0;
}