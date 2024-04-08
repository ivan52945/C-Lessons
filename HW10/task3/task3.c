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

void read_file(char in [], char s1 [], char s2 []) {
    FILE* f = open_file(in, "r");

    fscanf(f, "%s %s", s1, s2);

    fclose(f);
}

void print_file(char out [], char s []) {
    FILE* f = open_file(out, "w");

    fprintf(f, "%s", s);

    fclose(f);
}

void count_freq(char s [], int freq []) {
    int len = strlen(s);

    for(int i = 0; i < len; i++)
        freq[s[i] - 'a'] += 1;
}


void find_unike_in_2_words(char s1 [], char s2 [], char s_out []) {

    int pos = 0;
    int freq1[26] = {};

    int freq2[26] = {};

    count_freq(s1, freq1);
    count_freq(s2, freq2);

    for(int i = 0; i < 26; i++)
        if(freq1[i] == 1 && freq2[i] == 1) {
            s_out[pos++] = i + 'a';
            s_out[pos++] = ' ';
        }

    if(pos > 1)
        s_out[pos - 1] = '\0';
    else
        s_out[0] = '\0';
}

int main() {

    char s2[SIZE];
    char s1[SIZE];
    char* out = "output.txt";
    char s_out[SIZE];
    char* in = "input.txt";

    read_file(in, s1, s2);

    find_unike_in_2_words(s1, s2, s_out);

    print_file(out, s_out);

    return 0;
}