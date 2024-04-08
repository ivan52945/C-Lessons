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

void replace(char src [], char dst []) {
    int count = 0;
    for(int i = 0; i < strlen(src); i++) {
        if(!memcmp(src + i, "Ling", 4)) {
            strcat(dst + count, "Cao");
            count += 3;
            i += 4;
        }
        dst[count++] = src[i];
    }
}

int main() {
    char s_in[SIZE] = "";
    char* out = "output.txt";
    char s_out[SIZE] = "";
    char* in = "input.txt";

    read_file(in, s_in);

    replace(s_in, s_out);

    print_file(out, s_out);

    return 0;
}