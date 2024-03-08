#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa, int* pb) {
    int n_items = 0;

    n_items = scanf("%d%d", pa, pb);
    if(n_items != 2 || *pa > *pb || *pa > 101 || *pb > 101) {
        printf("Error: invalid input, expected integers a > b and a,b <= 100\n");
        abort();
    }
}

int main() {
    int a, b;
    unsigned long long squareSum = 0;

    read_input(&a, &b);

    for(int i = a; i <= b; i += 1) {
        squareSum += i * i;
    }

    printf("%lld\n", squareSum);

    return 0;
}