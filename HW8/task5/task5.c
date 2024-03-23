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

void reverse_arr(int arr [], int size) {
    int tmp;
    int semi_size = size / 2;

    for(int i = 0; i < semi_size; i++) {
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
}

int main() {
    int arr[SIZE];

    int parts = 2;
    int shift = SIZE / parts;

    read_input_arr(arr, SIZE);

    for(int i = 0; i < 2; i++) {
        reverse_arr(arr + shift * i, shift);
    }

    print_arr(arr, SIZE);

    puts("\n");

    return 0;
}