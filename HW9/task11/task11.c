#define NOTEST 0
#define SIZE 10

#if NOTEST

#include <stdio.h>
#include <stdlib.h>

int count_bigger_abs(int n, int a []);

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any 1 integer\n");
        abort();
    }
}

void read_input_arr(int size, int arr []) {
    for(int i = 0; i < size; i++)
        read_input(arr + i);
}


void print_arr(int size, int arr []) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main() {
    int arr[SIZE];
    int count_bigger_abs_out;

    read_input_arr(SIZE, arr);


    count_bigger_abs_out = count_bigger_abs(SIZE, arr);

    printf("%d\n", count_bigger_abs_out);

    return 0;
}

#endif

int max(int size, int arr []) {
    int max = arr[0];

    for(int i = 1; i < size; i++)
        if(arr[i] > max) {
            max = arr[i];
        }

    return max;
}

int abs(int n) {
    return (n < 0) ? -n : n;
}

int count_bigger_abs(int n, int a []) {
    int count = 0;
    int max_in = max(n, a);

    for(int i = 0; i < n; i++)
        if(abs(a[i]) > max_in) {
            count += 1;
        }

    return count;
}