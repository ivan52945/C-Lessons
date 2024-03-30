#include <stdio.h>
#include <stdlib.h>

void read_input(char* pa, int* pb) {
    int n_items = 0;
    int check_letter;
    int check_number;

    n_items = scanf("%c%d", pa, pb);

    check_letter = *pa >= 'A' && *pa <= 'H';
    check_number = *pb >= 1 && *pb <= 8;

    if(n_items != 2 && check_letter && check_number) {
        printf("Error: invalid input, expected letter between A and H and number between 1 and 8\n");
        abort();
    }
}

int main() {

    int wht;
    int col, row;
    char row_с;

    read_input(&row_с, &col);

    row = row_с - ('A' - 1);

    wht = (row % 2) != (col % 2);

    if(wht)
        printf("WHITE\n");
    else
        printf("BLACK\n");

    return 0;
}