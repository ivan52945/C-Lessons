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

void zero_tens(int arr [], int size, int zero_tens_out [], int* zero_tens_n) {
    int tens;

    for(int i = 0; i < size; i++) {
        tens = arr[i] / 10 % 10;

        if(tens == 0) {
            zero_tens_out[*zero_tens_n] = arr[i];
            *zero_tens_n += 1;
        }
    }
}

int main() {
    int arr[SIZE];

    int zero_tens_out[SIZE];

    int zero_tens_n = 0;

    read_input_arr(arr, SIZE);

    zero_tens(arr, SIZE, zero_tens_out, &zero_tens_n);

    print_arr(zero_tens_out, zero_tens_n);

    puts("\n");

    return 0;
}