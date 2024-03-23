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

int find_most_often(int arr [], int size) {
    int count = 1;
    int most_often = arr[0];
    int cur = arr[0];
    int max_count = 0;

    for(int i = 1; i < size; i++) {
        if(arr[i] == cur) {
            count += 1;
        }
        else {
            if(count > max_count) {
                max_count = count;
                most_often = cur;
            }
            cur = arr[i];
            count = 1;
        }
    }

    return (count > max_count) ? cur : most_often;
}

int main() {
    int arr[SIZE];

    int most_often_out;

    read_input_arr(arr, SIZE);

    sort(arr, SIZE);

    most_often_out = find_most_often(arr, SIZE);

    printf("%d\n", most_often_out);

    return 0;
}