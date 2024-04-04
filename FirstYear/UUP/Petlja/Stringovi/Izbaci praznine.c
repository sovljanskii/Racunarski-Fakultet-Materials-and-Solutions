#include <stdio.h>
#define MAX 100

void remove_spaces(char* s) {
    char* d = s;
    while (*s++ = *d++) {
        while (*d == ' ') {
            ++d;
        }
    }
}

int main() {
    char str[MAX];
    fgets(str,MAX,stdin);
    remove_spaces(str);
    fputs(str,stdout);
    return 0;
}
