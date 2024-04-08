#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10001

typedef struct {
    int lw;
    int up;
} T;

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

void print_file(char out [], int a, int b) {
    FILE* f = open_file(out, "w");

    fprintf(f, "%d %d", a, b);

    fclose(f);
}

T count_up_lw(char s []) {

    T count;
    int len = strlen(s);

    count.lw = 0;
    count.up = 0;

    for(int i = 0; i < len; i++) {
        if(s[i] >= 'a' && s[i] <= 'z')
            count.lw += 1;
        if(s[i] >= 'A' && s[i] <= 'Z')
            count.up += 1;
    }

    return count;
}

int main() {
    T count;
    char* out = "output.txt";
    char s[SIZE];
    char* in = "input.txt";

    read_file(in, s);

    count = count_up_lw(s);

    print_file(out, count.lw, count.up);

    return 0;
}