#include <stdio.h>
#include <stdlib.h>

void read_input(int* px1, int* py1, int* px2, int* py2) {
    int n_items = 0;

    n_items = scanf("%d%d%d%d", px1, py1, px2, py2);
    if(n_items != 4) {
        printf("Error: invalid input, expected any 4 integers\n");
        abort();
    }
}

int main() {

    float k, b;
    int x1, y1, x2, y2;

    read_input(&x1, &y1, &x2, &y2);

    k = (y2 - y1) * 1.0 / (x2 - x1);
    b = y1 - k * x1;

    printf("%.2f %.2f\n", k, b);

    return 0;
}