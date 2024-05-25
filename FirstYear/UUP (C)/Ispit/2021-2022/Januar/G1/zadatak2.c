#include <stdio.h>
#include <string.h>

#define MAX 255

//asadadio gladansam
void multiplyChar(char *S, int index, int count) {
    for (int i = 0; i < count - 1; i++) {
        int length = strlen(S);
        for (int j = length; j > index; j--) {
            S[j] = S[j - 1];
        }
        S[length + 1] = 0;
    }
}

void removeChar(char *S, int index) {
    char *p = S;
    int br = 0;
    for (int a = 0; S[br]; a++) {
        if (a == index) continue;
        S[br] = p[a];
        br++;
    }
}

void fun(char *S, char *P) {
    for (int i = 0; S[i]; i++) {
        int count = 0;
        for (int j = 0; P[j]; j++) {
            if (P[j] == S[i]) count++;
        }
        if (!count) {
            removeChar(S, i);
            i--;
        } else {
            multiplyChar(S, i, count);
            i += count - 1;
        }
    }
}

int main() {
    char S[255], P[255];
    fgets(P, MAX, stdin);
    fgets(S, MAX, stdin);
    S[strlen(S) - 1] = 0;
    P[strlen(P) - 1] = 0;
    fun(S, P);
    fputs(S, stdout);
    return 0;
}