#include <stdio.h>

int acounter(void) {
    char a = getchar();

    if(a == '.')
        return 0;

    if(a == 'a')
        return 1 + acounter();
    else
        return acounter();
}

int main() {

    int acount = acounter();

    printf("%d\n", acount);

    return 0;
}