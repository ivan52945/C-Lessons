#include <stdio.h>
#include <stdlib.h>

#define SIZE 1002

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any 1 integer\n");
        abort();
    }
}

int read_input_arr_to_zero(int size, int arr []) {
    for(int i = 0; i < size; i++) {
        read_input(arr + i);
        if(!(arr[i]))
            return i;
    }
    return size - 1;
}

int missing_value(int size, int arr []) {
    int min = arr[0];
    int sum = arr[0];

    int buf, sum_arifm, max;

    for(int i = 1; i < size; i++) {
        buf = arr[i];
        min = (buf < min) ? buf : min;
        sum += buf;
    }

    max = min + size;

    sum_arifm = (max + min) * (size + 1) / 2;

    return sum_arifm - sum;
}

int main() {
    int missed_out, size;
    int arr[SIZE];

    size = read_input_arr_to_zero(SIZE, arr);

    missed_out = missing_value(size, arr);

    printf("%d\n", missed_out);

    return 0;
}

