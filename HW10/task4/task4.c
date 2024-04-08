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

void a2b_and_b2a(char s []) {
    int len = strlen(s);

    for(int i = 0; i < len; i++) {
        if(s[i] == 'a' || s[i] == 'A')
            s[i] += 1;
        else if(s[i] == 'b' || s[i] == 'B')
            s[i] -= 1;
    }
}

int main() {

    char s[SIZE];
    char* out = "output.txt";
    char* in = "input.txt";

    read_file(in, s);

    a2b_and_b2a(s);

    print_file(out, s);

    return 0;
}