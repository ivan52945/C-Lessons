#include <stdio.h>
#include <stdlib.h>

#define SIZE 26

FILE* open_file(char name [], char format []) {
    FILE* f = fopen(name, format);

    if(!f) {
        printf("Error: open read file %s", name);
        abort();
    }

    return f;
}

void read_file(char in [], int* pa) {
    int n;
    FILE* f = open_file(in, "r");

    n = fscanf(f, "%d", pa);

    if(n < 1) {
        printf("Error: cannot read file %s", in);
        abort();
    }

    fclose(f);
}

void print_file(char out [], char str []) {
    FILE* f = open_file(out, "w");

    fprintf(f, "%s", str);

    fclose(f);
}

int main() {
    int n;

    char* in = "input.txt";
    char* out = "output.txt";
    char res[SIZE];

    read_file(in, &n);

    for(int i = 0; i < n; i += 2) {
        res[i] = i / 2 + 'A';
        res[i + 1] = i % 8 + '2';
    }

    print_file(out, res);

    return 0;
}