#include <stdio.h>
#include <string.h>
#define MAX 100

int palindrom(char *str,int start,int end){
    for (int i=0;i<=(end-start)/2;i++){
        if (str[start+i]==str[end-i]) continue;
        return 0;
    }
    return 1;
}
void toUpper(char *str,int start,int end){
    for (int i=0;i<=end-start;i++){
        str[start+i] -=32;
    }
}
void izokreni(char *str,int start,int end){
    for (int i=0;i<=(end-start)/2;i++){
       int rez = str[start+i];
       str[start+i] = str[end-i];
       str[end-i] = rez;
    }
}

void fun(char *str){
    int base=0;
    for (int i=0;i<=strlen(str);i++){
        if (str[i]==' ' || str[i]==0){
            if (palindrom(str,base,i-1)){
                toUpper(str,base,i-1);
            }
            else izokreni(str,base,i-1);
            base=i+1;
        }
    }
}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    fun(str);
    fputs(str,stdout);
}