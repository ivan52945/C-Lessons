#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1001

FILE* open_file(char name [], char format []) {
    FILE* f = fopen(name, format);

    if(!f) {
        printf("Error: open read file %s", name);
        abort();
    }

    return f;
}

void read_file(char in_f [], char s []) {
    FILE* f = open_file(in_f, "r");

    fscanf(f, "%[^\n]", s);

    fclose(f);
}

void print_file(char out_f [], char s []) {
    FILE* f = open_file(out_f, "w");

    fprintf(f, "%s", s);

    fclose(f);
}

void swap(char* pa, char* pb) {
    char tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void swap_neib_pares(char s []) {
    char* start = s;
    char* end = s;
    while(*end) {
        while(*start && *start == ' ')
            start += 1;

        end = start + 1;
        while(*end && *end == ' ')
            end += 1;

        if(*start && *end) {
            swap(start, end);
            start = end + 1;
        }
    }
}

int main() {
    char s[SIZE] = "";
    char* out = "output.txt";
    char* in = "input.txt";

    read_file(in, s);

    swap_neib_pares(s);

    print_file(out, s);

    return 0;
}