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

int delete_spaces(char s []) {
    int step = 0;
    int n = strlen(s);

    while(s[step] && s[step] == ' ')
        step += 1;

    for(int i = 0; i < n && s[i]; i++) {

        if(s[i + step] == ' ') {

            s[i++] = ' ';
            while(s[i + step] == ' ') {
                step += 1;
            }

        }

        s[i] = s[i + step];
    }
    return n - step;
}

int main() {
    char s[SIZE] = "";
    char* out = "output.txt";
    char* in = "input.txt";

    read_file(in, s);

    delete_spaces(s);

    print_file(out, s);

    return 0;
}