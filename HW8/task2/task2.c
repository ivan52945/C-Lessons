#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

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

int min(int arr [], int size) {
    int min = arr[0];

    for(int i = 1; i < size; i++) {
        if(min > arr[i])
            min = arr[i];
    }

    return min;
}

int main() {
    int arr[SIZE];

    int min_out;

    read_input_arr(arr, SIZE);

    min_out = min(arr, SIZE);

    printf("%d\n", min_out);

    return 0;
}