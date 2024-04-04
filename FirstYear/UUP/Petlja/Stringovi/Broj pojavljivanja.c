#include <stdio.h>
#include <string.h>
#define MAX 100



int main() {
    char s[MAX],t[MAX];
    fgets(s,MAX,stdin);
    fgets(t,MAX,stdin);
    s[strlen(s)-1]=0;
    t[strlen(t)-1]=0;

    int br=0;
    for (int i=0;i< strlen(s);i++){
        if (s[i]==t[0]){
            int pretpostavka=1;
            for (int j=0;j< strlen(t);j++){
                if(s[i+j]==t[j]) continue;
                pretpostavka=0; break;
            }
            if (pretpostavka){
                br++;
            }
        }
    }
    printf("%d",br);
    return 0;
}
