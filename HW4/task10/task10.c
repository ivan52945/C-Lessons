#include <stdio.h>
#include <stdlib.h>

void read_input(int* pa) {
    int n_items = 0;

    n_items = scanf("%d", pa);
    if(n_items != 1) {
        printf("Error: invalid input, expected any 5 integer numbers\n");
        abort();
    }
}

int main() {
    int mounth, seasonI;

    read_input(&mounth);

    seasonI = ((mounth + 10) % 12) / 3;

    switch(seasonI) {
        case 0:
        {
            printf("spring\n");
            break;
        }
        case 1:
        {
            printf("summer\n");
            break;
        }
        case 2:
        {
            printf("autumn\n");
            break;
        }
        case 3:
        {
            printf("winter\n");
            break;
        }
    }

    return 0;
}