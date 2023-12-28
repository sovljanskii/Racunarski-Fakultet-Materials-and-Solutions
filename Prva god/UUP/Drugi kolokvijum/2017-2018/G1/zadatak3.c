#include <stdio.h>
#include <string.h>
#define MAX 100

void removeStr(int a,int b, char *str){
    int i=0;
    for (;str[b+i];i++){
        str[a+i] = str[b+i+1];
    }
}

int nadjiStr(int a, int b, char *str){
    for (int i=b;str[i];i++){
        if (str[i]==str[a]){
            int nadjen = 1;
            int j=1;
            for (;str[j]!=' ';j++){
                if (str[a+j]==str[i+j]) continue;
                nadjen = 0; break;
            }
            if (nadjen){
                removeStr(i,i+j,str);
                return 1;
            }
        }
    }
    return 0;
}

void srediStr(char *str){
    int base=0;
    for (int i=0;str[i];i++){
        if (str[i]==' '){
            nadjiStr(base,i-1,str);

            base = i+1;
        }
    }
}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    srediStr(str);

    fputs(str,stdout);
    return 0;
}