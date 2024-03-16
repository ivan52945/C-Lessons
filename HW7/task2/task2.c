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

void print_num(int num) {

    if(num > 9)
        print_num(num / 10);

    printf("%d ", num % 10);
}


int main() {
    int a;

    read_input(&a);

    print_num(a);

    printf("\n");

    return 0;
}