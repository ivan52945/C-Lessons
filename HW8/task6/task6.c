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

void read_input_arr(int arr [], int size) {
    for(int i = 0; i < size; i++)
        read_input(arr + i);
}


void print_arr(int arr [], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void shift_cycle_right(int arr [], int size) {
    int tmp = arr[size - 1];

    for(int i = size - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = tmp;
}

int main() {
    int arr[SIZE];

    int parts = 2;
    int shift = SIZE / parts;

    read_input_arr(arr, SIZE);

    shift_cycle_right(arr, SIZE);

    print_arr(arr, SIZE);

    puts("\n");

    return 0;
}