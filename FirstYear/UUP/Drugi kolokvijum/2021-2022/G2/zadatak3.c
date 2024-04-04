#include <stdio.h>
#include <string.h>
#define MAX 100

int removeStr(int a,int b,char *str){
    int i=0;
    for (;str[b+i];i++){
        str[a+i] = str[b+i+1];
    }
}

int nadjiStr(int a,int b,char *str){
    for (int i= strlen(str)-1;i>=0;i--){
        if (str[a]==str[i] && str[i]!=' ' &&(i<a || i>b)){

            int nadjen=1;
            for (int k=a,x=0;k<=b;k++,x++){
                if (str[k]==str[i-x]) continue;
                nadjen=0;break;
            }
            if (nadjen) return 1;
        }
    }
    return 0;
}

void srediStr(char *str){
    int base=0;
    for (int i=0;str[i];i++){
        if (str[i]==' '){
            if (!nadjiStr(base,i-1,str)){
                removeStr(base,i,str);
                i--;
            }
            else base=i+1;
        }
    }
    if (!nadjiStr(base, strlen(str)-1,str)){
        removeStr(base,strlen(str)-1,str);
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