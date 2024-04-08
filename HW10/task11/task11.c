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

void read_file(char in [], char s []) {
    FILE* f = open_file(in, "r");

    fscanf(f, "%[^\n]", s);

    fclose(f);
}

void print_file(char out [], char s []) {
    FILE* f = open_file(out, "w");

    fprintf(f, "%s", s);

    fclose(f);
}

void change_ext_to_html(char s []) {
    char* point;

    point = strrchr(s, '/');

    while(*point && *point != '.')
        point += 1;

    strcpy(point, ".html");
}

int main() {
    char s[SIZE];
    char* out = "output.txt";

    char* in = "input.txt";

    read_file(in, s);

    change_ext_to_html(s);

    print_file(out, s);

    return 0;
}