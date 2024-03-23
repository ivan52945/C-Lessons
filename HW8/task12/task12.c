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

void sort(int arr [], int size) {
    int tmp;

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void select_single(int arr [], int size, int single [], int* single_n) {
    int count = 1;
    int cur = arr[0];
    int sng_n_t = 0;

    for(int i = 1; i < size; i++) {
        if(arr[i] == cur) {
            count += 1;
        }
        else {
            if(count == 1) {
                single[sng_n_t] = cur;
                sng_n_t += 1;
            }
            cur = arr[i];
            count = 1;
        }
    }

    if(count == 1) {
        single[sng_n_t] = cur;
        sng_n_t += 1;
    }

    *single_n = sng_n_t;
}

int main() {
    int arr[SIZE];

    int single_out[SIZE];

    int single_n = 0;

    read_input_arr(arr, SIZE);

    sort(arr, SIZE);

    select_single(arr, SIZE, single_out, &single_n);

    print_arr(single_out, single_n);

    puts("\n");

    return 0;
}