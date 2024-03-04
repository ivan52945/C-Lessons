#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2) {
        printf("Error: invalid input, expected any 2 integer numbers\n");
        abort();
    }
}

int main() {
    int a, b;

    read_input(&a, &b);

#if 0
    if(a > b) printf("%d %d", b, a);
    else printf("%d %d", a, b);
#endif

#if 1
    if(a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    else printf("%d %d", a, b);
#endif

    return 0;
}