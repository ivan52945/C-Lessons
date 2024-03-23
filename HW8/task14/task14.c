#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 30

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

void divide_to_digits(int num, int arr [], int* pos) {
    int last;

    for(last = MAX_DIGITS - 1; num > 0; last--) {
        arr[last] = num % 10;
        num /= 10;
    }

    *pos = last + 1;
}

int main() {
    int num, pos, count;


    int arr[MAX_DIGITS] = { 0 };

    read_input(&num);

    divide_to_digits(num, arr, &pos);

    count = MAX_DIGITS - pos;

    print_arr(arr + pos, count);

    puts("\n");

    return 0;
}