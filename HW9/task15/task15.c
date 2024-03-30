#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

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

float diag_avg(int n, int arr[n][n]) {
    int diag_avg = 0;

    for(int i = 0; i < n; i++)
        diag_avg += arr[i][i];

    return (float)diag_avg / n;
}

int n_more_diag_avg(int n, int arr[n][n]) {
    float avg = diag_avg(n, arr);
    int count = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(arr[i][j] > avg)
                count += 1;
        }

    return count;
}

int main() {
    int arr[SIZE][SIZE];
    int n_more_diag_avg_out;

    read_input_arr_2(SIZE, SIZE, arr);

    n_more_diag_avg_out = n_more_diag_avg(SIZE, arr);

    printf("%d", n_more_diag_avg_out);

    return 0;
}