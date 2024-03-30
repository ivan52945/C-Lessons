#define NOTEST 0

#if NOTEST

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int sum_between_ab(int from, int to, int size, int a []);

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any 1 integer\n");
        abort();
    }
}

void read_input_2(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2) {
        printf("Error: invalid input, expected any 2 integers for [from, to]\n");
        abort();
    }
}

void read_input_arr(int size, int arr []) {
    for(int i = 0; i < size; i++)
        read_input(arr + i);
}

int main() {

    int arr[SIZE];
    int sum_between_ab_out;
    int from, to;

    read_input_2(&from, &to);

    read_input_arr(SIZE, arr);

    sum_between_ab_out = sum_between_ab(from, to, SIZE, arr);

    printf("%d\n", sum_between_ab_out);

    return 0;
}

#endif

void swap(int* pa, int* pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int is_unike(int pos, int a []) {
    int tmp = a[pos];

    for(int i = 0; i < pos; i++)
        if(tmp == a[i]) {
            return 0;
        }

    return 1;
}

int sum_between_ab(int from, int to, int size, int a []) {

    int sum = 0;

    if(to < from)
        swap(&to, &from);

    for(int i = 0; i < size; i++)
        if(from <= a[i] && a[i] <= to) {
            if(is_unike(i, a))
                sum += a[i];
        }

    return sum;
}