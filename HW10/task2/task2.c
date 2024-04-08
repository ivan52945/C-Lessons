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

void find_sim_with_last(char s [], char out []) {
    int len;
    int pos = 0;
    char last;


    len = strlen(s) - 1;
    last = s[len];

    for(int i = 0; i < len; i++)
        if(s[i] == last) {
            out[pos++] = i + '0';
            out[pos++] = ' ';
        }

    if(pos > 1)
        out[pos - 1] = '\0';
    else
        out[0] = '\0';
}

int main() {

    char s_in[SIZE];
    char* out = "output.txt";
    char s_out[SIZE];
    char* in = "input.txt";

    read_file(in, s_in);

    find_sim_with_last(s_in, s_out);

    print_file(out, s_out);

    return 0;
}