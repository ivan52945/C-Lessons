#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 30

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any integer a > 0\n");
        abort();
    }
}

void divide_to_digits(int num, int arr [], int* pos) {
    int last;

    for(last = MAX_DIGITS - 1; num > 0; last--) {
        arr[last] = num % 10;
        num /= 10;
    }

    *pos = last + 1;
}

void sort_down(int arr [], int size) {
    int tmp;

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int unite_digits(int arr [], int size) {
    int num = 0;

    for(int i = 0; i < size; i++) {
        num = num * 10 + arr[i];
    }

    return num;
}

int main() {
    int num, num_out, pos, count_dig;

    int buff[MAX_DIGITS];

    int* buff_p = buff;

    read_input(&num);

    if(num > 9) {
        divide_to_digits(num, buff, &pos);

        count_dig = MAX_DIGITS - pos;
        buff_p = buff + pos;

        sort_down(buff_p, count_dig);

        num_out = unite_digits(buff_p, count_dig);
    }
    else {
        num_out = num;
    }
    printf("%d", num_out);

    return 0;
}