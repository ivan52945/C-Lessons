#define NOTEST 1

#if NOTEST

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void swap_negmax_last(int size, int a []);

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any integer\n");
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

    read_input_arr(SIZE, arr);

    swap_negmax_last(SIZE, arr);

    print_arr(SIZE, arr);

    return 0;
}

void swap(int* pa, int* pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

#endif

void swap_negmax_last(int size, int a []) {
    int max_neg = 0;
    int max_neg_i;

    for(int i = 0; i < size; i++)
        if(a[i] < 0 && (a[i] > max_neg || !max_neg)) {
            max_neg = a[i];
            max_neg_i = i;
        }

    if(max_neg)
        swap(a + max_neg_i, a + size - 1);
}