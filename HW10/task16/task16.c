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

/*
    можно решать 2мя способами
    первый через сортировку
    второй через подсчёт букв
*/

#if 0
void bubbleSort(int n, char a []) {

    char tmp;
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
#endif

void max_polyndrom(char s [], char p []) {
#if 0
    int i = 0;
    int l = 0;
    int n = strlen(s);
    char c = 0;
    bubbleSort(n, s);


    while(i < n) {
        if(s[i] == s[i + 1]) {
            p[l++] = s[i];
            i += 2;
        }
        else if(!c)
            c = s[i];
        else
            i += 1;
    }

    l *= 2;

    for(i = 0; i < l / 2; i++)
        p[l - i] = p[i];

    p[i] = c;

    p[l + 1] = '\0';
#endif

    int l = 0;
    int letters[26] = { 0 };
    char c = -1;

    for(int i = 0; i < strlen(s);i++)
        letters[s[i] - 'a'] += 1;

    for(int i = 0; i < 26; i++) {
        while(letters[i] > 1) {
            p[l++] = i + 'a';
            letters[i] -= 2;
        }
        if(letters[i] && c == -1)
            c = i + 'a';
    }

    p[l] = c;

    for(int i = 0; i < l; i++)
        p[2 * l - i] = p[i];

    p[2 * l + 1] = '\0';
}

int main() {

    char s[SIZE];
    char* out = "output.txt";
    char p[SIZE];
    char* in = "input.txt";

    read_file(in, s);

    max_polyndrom(s, p);

    print_file(out, p);

    return 0;
}