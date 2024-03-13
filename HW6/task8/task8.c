#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1 || *pa < 10) {
        printf("Error: invalid input, expected any 1 integer a > 10\n");
        abort();
    }
}

int is_happy_number(int n) {

    int digit;
    int mult = 1;
    int sum = 0;

    while(n > 0) {
        digit = n % 10;

        if(digit != 0) {
            sum += digit;
            mult *= digit;
        }
        else {
            sum = 1;
            mult = 0;
            break;
        }

        n /= 10;
    }

    return (sum == mult) ? 1 : 0;

}

int main() {
    int a, t;

    read_input(&a);

    t = is_happy_number(a);

    if(t)
        printf("YES\n");

    else
        printf("NO\n");

    return 0;
}