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

void print_file(char out [], int n, int a []) {
    FILE* f = open_file(out, "w");

    for(int i = 0; i < n; i++)
        fprintf(f, "%d ", a[i]);

    fclose(f);
}

void bubbleSort(int n, int a []) {
    int tmp;
    int flag = 1;

    for(int i = 0; i < n && flag; i++) {
        flag = 0;
        for(int j = 1; j < n - i; j++)
            if(a[j] < a[j - 1]) {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
                flag = 1;
            }
    }
}

int select_nums(char s [], int a []) {
    char* p;
    int len = strlen(s);
    int n = 0;

    for(int i = 0; i < len && s[i]; i++)
        if(s[i] >= '0' && s[i] <= '9') {
            for(p = s + i; i < len && s[i] >= '0' && s[i] <= '9';i++) { }
            s[i] = '\0';
            a[n++] = atoi(p);
        }

    return n;
}

int main() {
    int a[40];
    char* out = "output.txt";
    int n = 0;
    char s[SIZE];

    char* in = "input.txt";

    read_file(in, s);

    n = select_nums(s, a);

    bubbleSort(n, a);

    print_file(out, n, a);

    return 0;
}