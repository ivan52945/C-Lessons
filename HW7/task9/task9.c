#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2 || *pa < 0 || *pb < 0) {
        printf("Error: invalid input, expected integers a, b > 0\n");
        abort();
    }
}

int akkerman(int n, int m) {
    if(n == 0)
        return m + 1;
    else if(m == 0)
        return akkerman(n - 1, 1);
    else {
        int akk_m = akkerman(n, m - 1);
        return akkerman(n - 1, akk_m);
    }
}

int main() {
    int n, m;

    unsigned long akk_out;

    read_input(&n, &m);

    akk_out = akkerman(n, m);

    printf("%lu", akk_out);

    return 0;
}