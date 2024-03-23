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

float avg(int arr [], int size) {
    float sum = 0;

    for(int i = 0; i < size; i++)
        sum += arr[i];

    return sum / size;
}

int main() {
    int arr[SIZE];

    float avg_out;

    read_input_arr(arr, SIZE);

    avg_out = avg(arr, SIZE);

    printf("%.3f\n", avg_out);

    return 0;
}