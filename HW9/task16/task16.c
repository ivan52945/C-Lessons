#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

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

int even_more_noeven(int size, int arr []) {
    int n_even = 0;
    int n_neven = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] % 2)
            n_neven += 1;
        else
            n_even += 1;
    }

    return n_even > n_neven;
}

int repl_num_by_mult_dgt(int n, int ev_more_nev) {
    int dig;
    int mult = 1;

    while(n > 0) {
        dig = n % 10;

        if((dig % 2) == ev_more_nev)
            mult *= dig;

        n /= 10;
    }

    return mult;
}

void print_arr(int size, int arr []) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main() {
    int arr[SIZE];
    int ev_more_noev;

    read_input_arr(SIZE, arr);

    ev_more_noev = even_more_noeven(SIZE, arr);

    for(int i = 0; i < SIZE; i++)
        if((arr[i] % 2) == ev_more_noev) {
            arr[i] = repl_num_by_mult_dgt(arr[i], ev_more_noev);
        }


    print_arr(SIZE, arr);

    puts("\n");

    return 0;
}