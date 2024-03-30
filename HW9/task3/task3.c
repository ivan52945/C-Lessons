// для проверки работоспособности всей программы нужно в строчке в #define NOTEST поставить 1 вместо 0

#define NOTEST 1

#if NOTEST

#define SIZE 99
#include <stdio.h>
#include <stdlib.h>

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

int find_max_array(int size, int a []);

int main() {
    int max;
    int arr[SIZE];

    read_input_arr(SIZE, arr);

    max = find_max_array(SIZE, arr);

    printf("%d\n", max);

    return 0;
}

#endif

int find_max_array(int size, int a []) {
    int max = a[0];

    for(int i = 1; i < size; i++)
        if(a[i] > max) {
            max = a[i];
        }

    return max;
}
