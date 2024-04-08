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

int is_palindrom(char s []) {

    int letters[26] = { 0 };
    int c = 0;

    for(int i = 0; i < strlen(s);i++)
        if(s[i] >= 'a' && s[i] <= 'z') {
            letters[s[i] - 'a'] += 1;
        }

    for(int i = 0; i < 26; i++) {
        if((letters[i] % 2) && c)
            return 0;
        else if((letters[i] % 2) && !c)
            c = 1;
    }

    return 1;
}

int main() {

    int is_p;
    char* in = "input.txt";
    char s[SIZE];

    read_file(in, s);

    is_p = is_palindrom(s);

    if(is_p)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}