#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1 || *pa < 0) {
        printf("Error: invalid input, expected any integer >=0 \n");
        abort();
    }
}

int grow_up(int n) {
    int prew;
    int temp = 9;
    int flag = 1;

    while(n > 0) {
        prew = n % 10;

        if(prew > temp) {
            flag = 0;
            break;
        }

        n = n / 10;
        temp = prew;
    }

    return flag;
}

int main() {
    int a, t;

    read_input(&a);

    t = grow_up(a);

    if(t)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}