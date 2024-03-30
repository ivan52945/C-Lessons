#define NOTEST 1

#if NOTEST

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void change_max_min(int size, int a []);

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

    change_max_min(SIZE, arr);

    print_arr(SIZE, arr);

    return 0;
}

#endif

void swap(int* pa, int* pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void change_max_min(int size, int a []) {
    int max_i = 0;
    int min_i = 0;

    for(int i = 1; i < size; i++) {
        max_i = (a[i] > a[max_i]) ? i : max_i;
        min_i = (a[i] < a[min_i]) ? i : min_i;
    }

    swap(a + max_i, a + min_i);
}