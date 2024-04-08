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

void print_file(char out [], int a) {
    FILE* f = open_file(out, "w");

    fprintf(f, "%d", a);

    fclose(f);
}

int count_aends(char s []) {
    int l;
    int n_a = 0;
    char* p;

    p = strtok(s, " ");

    while(p != NULL) {
        l = strlen(p);

        if(p[l - 1] == 'a')
            n_a += 1;

        p = strtok(NULL, " ");
    }

    return n_a;
}


int main() {

    int n_a;
    char* out = "output.txt";
    char s[SIZE];
    char* in = "input.txt";

    read_file(in, s);

    n_a = count_aends(s);

    print_file(out, n_a);

    return 0;
}