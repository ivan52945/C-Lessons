#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

FILE* open_file(char name [], char format []) {
    FILE* f = fopen(name, format);

    if(!f) {
        printf("Error: open read file %s", name);
        abort();
    }

    return f;
}

void read_file(char in [], char s1 [], char s2 []) {
    FILE* f = open_file(in, "r");

    fscanf(f, "%s %s", s1, s2);

    fclose(f);
}

void print_file(char out [], char s1 [], char s2 []) {
    FILE* f = open_file(out, "w");

    fprintf(f, "Hello, %s %s!", s1, s2);

    fclose(f);
}

int main() {

    char* out = "output.txt";
    char name[SIZE];
    char surname[SIZE];
    char* in = "input.txt";

    read_file(in, surname, name);

    print_file(out, name, surname);

    return 0;
}