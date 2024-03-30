// для проверки работоспособности всей программы нужно в строчке в #define NOTEST поставить 1 вместо 0
#define NOTEST 1
#define SIZE 20

#if NOTEST

#include <stdio.h>
#include <stdlib.h>

void sort_even_odd(int n, int a []);

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any 1 integer\n");
        abort();
    }
}

void read_input_arr(int size, int arr []) {
    for(int i = 0; i < size; i++) {
        read_input(arr + i);
    }

}


void print_arr(int size, int arr []) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main() {
    int arr[SIZE];

    read_input_arr(SIZE, arr);

    sort_even_odd(SIZE, arr);

    print_arr(SIZE, arr);

    return 0;
}

#endif

void sort_even_odd(int n, int a []) {

    int od_n = 0;
    int ev_n = 0;
    int* pa = a;

    int even[SIZE];
    int odd[SIZE];

    for(int i = 0; i < n; i++) {
        if(a[i] % 2)
            odd[od_n++] = a[i];
        else
            even[ev_n++] = a[i];
    }

    for(int i = 0; i < ev_n; i++)
        pa[i] = even[i];

    pa += ev_n;

    for(int i = 0; i < od_n; i++)
        pa[i] = odd[i];
}

//без сохранения порядка

#if 0
int tmp;
int j = n - 1;
int i = 0;

while(i < j) {
    while((a[i] % 2) == 0) i++;
    while((a[j] % 2) != 0) j--;

    if(i < j) {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}
#endif