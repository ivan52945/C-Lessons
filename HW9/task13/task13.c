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

int track(int n, int arr[n][n]) {
    int track_res = 0;

    for(int i = 0; i < n; i++)
        track_res += arr[i][i];

    return track_res;
}

int main() {

    int track_out;
    int arr[SIZE][SIZE];

    read_input_arr_2(SIZE, SIZE, arr);

    track_out = track(SIZE, arr);

    printf("%d", track_out);

    return 0;
}