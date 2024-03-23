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

int sum_pos(int arr [], int size) {
    int sum_pos = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] > 0)
            sum_pos += arr[i];
    }

    return sum_pos;
}

int main() {
    int arr[SIZE];

    int sum_pos_out;

    read_input_arr(arr, SIZE);

    sum_pos_out = sum_pos(arr, SIZE);

    printf("%d\n", sum_pos_out);

    return 0;
}