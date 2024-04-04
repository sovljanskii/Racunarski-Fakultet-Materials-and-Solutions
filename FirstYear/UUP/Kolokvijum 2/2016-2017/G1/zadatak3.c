#include <stdio.h>
#include <string.h>

#define MAX 256

void izbaciRec(char *str, int pocetak, int kraj) {
    int i;
    for (i = 0; str[kraj + i] != '0'; i++) {
        str[pocetak + i] = str[kraj + i];
    }
    str[pocetak + i] = 0;
}

void sredi(char *str) {
    int prvo = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            if (str[prvo] > 'a' && str[prvo] <= 'z' && str[i - 1] >= 'a' && str[i - 1] <= 'z') {
                izbaciRec(str, prvo, i + 1);
            }
            prvo = i + 1;
        }
    }
}

int main() {
    char str[MAX];
    fgets(str, MAX, stdin);
    sredi(str);
    fputs(str, stdout);
    return 0;
}