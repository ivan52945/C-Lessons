#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 0;

    char c;

    while((c = getchar()) != '.' && count >= 0) {
        if(c == '(')
            count += 1;
        else if(c == ')')
            count -= 1;
    }

    if(count == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}