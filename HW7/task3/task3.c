#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2) {
        printf("Error: invalid input, expected any 2 integers\n");
        abort();
    }
}

void print_num(int a, int b) {

    if(a != b) {
        if(a < b)
            printf("%d ", a++);
        else
            printf("%d ", a--);
        print_num(a, b);
    }
    else {
        printf("%d ", a);
    }

}


int main() {
    int a, b;

    read_input(&a, &b);

    print_num(a, b);

    printf("\n");

    return 0;
}