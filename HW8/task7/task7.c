#include <stdio.h>
#include <stdlib.h>

#define SIZE 12

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

void shift_cycle_right(int arr [], int size, int shift) {
    int tmp[SIZE];

    int dif = size - shift;

    for(int i = dif; i < size; i++) {
        tmp[i - dif] = arr[i];
    }

    for(int i = size - 1; i >= shift; i--) {
        arr[i] = arr[i - shift];
    }

    for(int i = 0; i < shift; i++) {
        arr[i] = tmp[i];
    }
}

int main() {
    int arr[SIZE];

    read_input_arr(arr, SIZE);

    shift_cycle_right(arr, SIZE, 4);

    print_arr(arr, SIZE);

    puts("\n");

    return 0;
}