#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1 || *pa < 0 || *pa > 90) {
        printf("Error: invalid input, expected any integer betweeen 0 and 90\n");
        abort();
    }
}

float abs_f(float x) {
    return (x < 0) ? -x : x;
}

float cosinus(float x) {
    const float PI = 3.1415926535;

    float res = 1;
    float temp = 1;

    float xRad = PI / 180 * x;

    for(int i = 2; abs_f(temp); i += 2) {
        temp *= -1 * (xRad * xRad) / (i * (i - 1));
        res += temp;
    }

    return res;
}

int main() {
    int a;
    float cosOut;

    read_input(&a);

    cosOut = cosinus(a);

    printf("%.3f\n", cosOut);

    return 0;
}