#include <stdio.h>
#include <string.h>
#define MAX 100

void sredi(char *s) {
    int length = strlen(s);
    int marker = 0;
    for (int i = 1; s[i-1]; i++) {
        if (s[i] == ' ' || s[i]==0) {
            int brisi = 1;
            for (int j = i + 1; s[j]; j++) {
                if (s[marker] == s[j]) {
                    int provera = 1;
                    for (int k = j, m = 0; s[k] != ' ' && s[k] != 0; k++, m++) {
                        if (s[k] == s[marker + m]) continue;
                        provera = 0;
                        break;
                    }
                    if (provera) { brisi = 0; break;}
                }


            }
            if (brisi) {
                for (int k = marker, m = 1; s[i + m]; k++, m++) {
                    s[k] = s[i + m];
                }
                length-=i-marker;
                s[length-1]=0;
            }
            else marker = i + 1;

        }
    }
    s[length-1]=0;

}

int main() {
    char s[MAX];
    fgets(s,MAX,stdin);
    s[strlen(s)-1]=0;
    sredi(s);
    fputs(s,stdout);
    return 0;
}