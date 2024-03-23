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

int srt_pr(int a, int b) {
    return (a % 10) > (b % 10);
}

void sort_by_last_digit(int arr [], int size) {
    int tmp;

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(srt_pr(arr[i], arr[j])) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}



int main() {
    int arr[SIZE];

    read_input_arr(arr, SIZE);

    sort_by_last_digit(arr, SIZE);

    print_arr(arr, SIZE);

    puts("\n");

    return 0;
}