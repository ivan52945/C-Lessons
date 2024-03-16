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

int cnt_1_in_bin(int a) {

    if(a > 1)
        return a % 2 + cnt_1_in_bin(a / 2);
    else
        return a;

}

int main() {
    int a, count_out;

    read_input(&a);

    count_out = cnt_1_in_bin(a);

    printf("%d\n", count_out);

    return 0;
}