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

int main() {
    int flag = 0;
    int a, digit_last, digit_prew;

    read_input(&a);

    if(a > 10) {
        while(a > 0) {

            digit_last = a % 10;
            a /= 10;
            digit_prew = a % 10;

            if(digit_last == digit_prew) {
                flag = 1;
                break;
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    else {
        printf("NO\n");
    }


    return 0;
}