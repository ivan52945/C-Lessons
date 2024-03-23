#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any 1 integer\n");
        abort();
    }
}

void print_formatted(int arr [], int size) {
    for(int i = 2; i < size; i++)
        printf("%d %d\n", i, arr[i]);
}

void count_multiples(int n, int arr [], int size) {
    for(int i = 2; i < size; i++) {
        arr[i] = n / i;
    }
}

int main() {
    int n;

    int arr[SIZE];

    read_input(&n);

    count_multiples(n, arr, SIZE);

    print_formatted(arr, SIZE);

    return 0;
}