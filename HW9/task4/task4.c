// для проверки работоспособности всей программы нужно в строчке в #define NOTEST поставить 1 вместо 0
#define NOTEST 1

#if NOTEST

#define SIZE 5
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

int is_two_same(int size, int a []);

int main() {
    int is_two_same_out;
    int arr[SIZE];


    read_input_arr(SIZE, arr);

    is_two_same_out = is_two_same(SIZE, arr);

    if(is_two_same_out)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

#endif

int is_two_same(int size, int a []) {

    for(int i = 0; i < size - 1; i++)
        for(int j = i + 1; j < size; j++) {
            if(a[i] == a[j])
                return 1;
        }

    return 0;
}
