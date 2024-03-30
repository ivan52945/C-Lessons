#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected integer number\n");
        abort();
    }
}

void read_input_arr(int size, int arr []) {
    for(int i = 0; i < size; i++)
        read_input(arr + i);
}

void swap(int* pa, int* pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void sum_min(int size, int arr []) {
    int min1 = 0;
    int min2 = 1;

    for(int i = 1; i < size; i++) {
        if(arr[i] < arr[min1]) {
            min2 = min1;
            min1 = i;
        }
        else if(arr[i] < arr[min2])
            min2 = i;
    }

    if(min2 < min1)
        swap(&min2, &min1);

    printf("%d %d", min1, min2);
}

int main() {
    int arr[SIZE];

    read_input_arr(SIZE, arr);

    sum_min(SIZE, arr);

    puts("\n");

    return 0;
}

