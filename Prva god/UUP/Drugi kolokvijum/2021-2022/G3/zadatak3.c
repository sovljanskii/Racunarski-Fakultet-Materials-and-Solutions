#include <stdio.h>
#include <string.h>
#define MAX 100


void stringSredi(char *str){
    int mark=0;
    for (int i=1;i-1< strlen(str);i++){
        if (str[i]==' '||str[i]=='\n'){
            for (int j=0;j<=(i-1-mark)/2;j++){
                if (str[mark+j] + j + 1>'9'){
                    str[mark+j] +=j-9;
                }
                else str[mark+j] +=j+1;
                if (j!=(i-1-mark)/2) {
                    if (str[i - 1 - j] + j + 1 > '9') {
                        str[i - 1 - j] += j - 9;
                    } else str[i - 1 - j] += j + 1;
                }
            }
            mark=i+1;
        }

    }
    str[strlen(str)-1]=0;

}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    stringSredi(str);
    fputs(str,stdout);
}