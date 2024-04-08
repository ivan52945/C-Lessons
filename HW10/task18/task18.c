#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 101

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

char sounds(char a) {
    switch(a) {
        case 'b':
        case 'f':
        case 'p':
        case 'v':
            return '1';
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
            return '2';
        case 'd':
        case 't':
            return '3';
        case 'l':
            return '4';
        case 'm':
        case 'n':
            return '5';
        case 'r':
            return '6';
        default:
            return ' ';
    }
}

//данный вариант запутанный, но по идее работать должен быстро
#if 0
int delete_spaces_and_sim(char s []) {

    char c;
    int n = strlen(s);
    int step = 0;

    for(int i = 1; i < n && s[i]; i += 1) {
        if(s[i + step] == ' ') {
            c = s[i];
            while(s[i + step] && (s[i + step] == ' ' || s[i + step] == c)) {
                step += 1;
            }
            s[i] = s[i + step];
        }
        if(s[i + step] == s[i]) {
            c = s[i++];
            while(s[i + step] && (s[i + step] == ' ' || s[i + step] == c)) {
                step += 1;
            }
            s[i--] = s[i + step];
        }
    }

    return n - step;
}
#endif

int delete_spaces(char s []) {
    int n = 0;

    for(int i = 0; s[i]; i++)
        if(s[i] != ' ') {
            s[n++] = s[i];
        }

    s[n] = '\0';
    return n;
}

int delete_spaces_and_sim(char s []) {
    int n;
    int step = 0;
    char c;

    n = delete_spaces(s);

    for(int i = 1; i < n - step && s[i]; i += 1) {
        if(s[i] == s[i - 1]) {
            c = s[i];
            while(s[i + step] && s[i + step] == c) {
                step += 1;
            }
            s[i] = s[i + step];
        }
    }
    s[n - step] = '\0';

    return n - step;
}



void soundex(char s []) {
    int len = strlen(s);

    //char sounds[26] = { ' ', '1', '2','3',' ' ,'1', '2', ' ' ,' ' ,'2', '2', '4', '5', '5', ' ', '1', '2', '6', '2', '3', ' ', '1', ' ', '2', ' ', '2' };

    for(int i = 1; i < len;i++)
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = sounds(s[i]);
        }

    len = delete_spaces_and_sim(s);

    for(int i = len; i < 5; i++) {
        s[i] = '0';
    }

    s[4] = '\0';
}

int main() {

    char s[SIZE] = "";
    char* out = "output.txt";
    char* in = "input.txt";

    read_file(in, s);

    soundex(s);

    print_file(out, s);

    return 0;
}

/*
    и как лучше делать преобразование букв в числа?
    через массив
    или через свич
*/