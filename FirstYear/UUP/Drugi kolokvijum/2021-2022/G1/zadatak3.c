#include <stdio.h>
#include <string.h>
#define MAX 100
//Ovo duplira iz nekog razloga??
void ispisiReci(char *str,int a1,int a2,int b1,int b2){
    for (int i=a1;i<a2;i++){
        printf("%c",str[i]);
    }
    printf(" ");
    for (int i=b1;i<b2;i++){
        printf("%c",str[i]);
    }
    printf("\n");

}
void checkword(char *str,int base, int end){
    int base2=0;
    for (int i=base;i<=end-1;i++){

        for (int j=end+1;str[j];j++){
            if (str[j]==' '){
                base2=j+1;
                continue;
                }
            if (str[i]==str[j] && str[i+1]==str[j+1]){
                int x=base2;
                for (;str[x]!=' '&&str[x]!=0;x++);
                ispisiReci(str,base,end,base2,x);
                for (;str[j]!=' ';j++);
                break;
            }
        }
    }
}

void fun (char *str){
    int base=0;
    for (int i=0;i< strlen(str);i++){
        if (str[i]==' '){
            checkword(str,base,i);
            base = i+1;
        }
    }
}

int main(){
    char str[MAX];
    fgets(str,MAX,stdin);
    str[strlen(str)-1]=0;
    fun(str);
    fputs(str,stdout);
    return 0;
}