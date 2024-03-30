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

void read_input_arr_2(int n, int m, int arr[n][n]) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            read_input(&arr[i][j]);
        }
}

int sum_max_in_rows(int n, int m, int arr[n][m]) {
    int max;
    int sum_max = 0;
    for(int i = 0; i < n; i++) {
        max = arr[i][0];

        for(int j = 1; j < m;j++)
            max = (arr[i][j] > max) ? arr[i][j] : max;

        sum_max += max;
    }

    return sum_max;
}

int main() {
    int arr[SIZE][SIZE];
    int sum_out;

    read_input_arr_2(SIZE, SIZE, arr);

    sum_out = sum_max_in_rows(SIZE, SIZE, arr);

    printf("%d", sum_out);

    return 0;
}