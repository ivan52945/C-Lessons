#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any integer\n");
        abort();
    }
}

int main() {
    int a, count;

    read_input(&a);

    for(count = 0; count <= 3 && a > 0; count += 1) {
        a /= 10;
    }

    if(a > 0 || count != 3)
        printf("NO");
    else
        printf("YES");

    return 0;
}