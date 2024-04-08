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

int is_space_or_equal(int pos, char s []) {
    if(s[pos] == ' ')
        return 0;

    for(int i = 0; i < pos; i++)
        if(s[i] == s[pos]) {
            return 0;
        }

    return 1;
}

int del_spaces_and_eq(char s []) {
    int len;
    int n = 0;

    len = strlen(s);
    if(len > 1) {
        for(int i = 0; i < len; i++)
            if(is_space_or_equal(i, s)) {
                s[n++] = s[i];
            }

        s[n] = '\0';
    }

    return len;
}

int main() {

    char s[SIZE] = "";
    char* out = "output.txt";
    char* in = "input.txt";

    read_file(in, s);

    del_spaces_and_eq(s);

    print_file(out, s);

    return 0;
}