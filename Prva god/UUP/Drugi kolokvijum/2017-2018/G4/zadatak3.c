#include <stdio.h>
#include <string.h>
#define MAX 255

void removeChar(char *str,int index){
    int next=index+1;
    while (str[next-1]){
        str[index] = str[next];
        next++;
        index++;
    }
}

int checkStr(char *str,int base,int end){
    for (int i=base;i<=end;i++){
        int br=1;
        for (int j=i+1;j<=end;j++){
            if(str[i]==str[j]){
                removeChar(str,j);
                end--;
                j--;
                br++;
            }
            if (br==2)break;
        }
        if (br<2){
            removeChar(str,i);
            end--;
            i--;
        }
    }
    return end;
}

void srediStr(char *str){
    int base=0;
    for (int i=0;str[i];i++){
        if (str[i]=='-'){
            base = checkStr(str,base,i-1) +2;
        }
    }
    int a= strlen(str);
    checkStr(str,base, strlen(str));
    if (a!= strlen(str))
        str[strlen(str)-1]=0;
}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    srediStr(str);
    fputs(str,stdout);
    return 0;
}