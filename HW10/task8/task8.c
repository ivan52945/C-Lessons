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

char* find_maxl(char s []) {
    int l;
    char* p;
    int max_l = 0;
    char* max;

    p = strtok(s, " ");

    while(p != NULL) {
        l = strlen(p);

        if(l > max_l) {
            max = p;
            max_l = l;
        }

        p = strtok(NULL, " ");
    }

    return max;
}

int main() {

    char* max;
    char* out = "output.txt";
    char s[SIZE];
    char* in = "input.txt";

    read_file(in, s);

    max = find_maxl(s);

    print_file(out, max);

    return 0;
}