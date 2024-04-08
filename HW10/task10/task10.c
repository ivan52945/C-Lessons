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

void spaces_to_new_lines(char* in, char* out) {

    FILE* f_in;
    char s[SIZE];
    FILE* f_out;

    f_in = open_file(in, "r");
    f_out = open_file(out, "w");

    while(fscanf(f_in, "%s", s) != EOF) {
        fprintf(f_out, "%s\n", s);
    }

    fclose(f_in);
    fclose(f_out);
}

int main() {
    char* in = "input.txt";
    char* out = "output.txt";

    spaces_to_new_lines(in, out);

    return 0;
}