#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb, int* pc) {
    int n_items = 0;

    n_items = scanf("%d%d%d", pa, pb, pc);
    if(n_items != 3) {
        printf("Error: invalid input, expected any 5 integer numbers\n");
        abort();
    }
}

int main() {
    int a, b, c;

    read_input(&a, &b, &c);

    if(a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    if(b > c) {
        int tmp = b;
        b = c;
        c = tmp;
    }

    if(a + b <= c) printf("NO\n");
    else printf("YES \n");

    return 0;
}