#include <stdio.h>
#include <string.h>
#define MAX 100

void sredi(char *s){
    int length = strlen(s);
    int marker=0;
    for (int i=1;s[i];i++){
       for (int j=marker;j<i;j++){
           if(s[i]==s[j]){
               for (int k=i;k<length;k++){
                   s[k]=s[k+1];

               }
               i--;
               length--;
           }
           if (s[i]=='-'){
               marker=i+1;
           }
       }
    }


}

int main() {
    char s[MAX];
    fgets(s,MAX,stdin);
    s[strlen(s)-1]=0;
    sredi(s);
    fputs(s,stdout);

    return 0;
}
