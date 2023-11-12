#include <stdio.h>
#include <math.h>
/*
Napisati funkciju int armstrong(int n) koja proverava da li je zadati broj n
Armstrongov. Broj je armstrongov ako može da se dobije kao zbir svih svojih cifara
stepenovanih na broj cifara.
 */
int brojCifara(int n){
    int br=0;
    while (n){
        br++;
        n/=10;
    }
    return br;
}

int armstrongovBroj(int n){
    int br=0;
    int rez=n;
    int brcifri = brojCifara(n);
    while (rez!=0){
        br=br+ (int)pow(rez%10, brcifri);
        rez/=10;
    }
    if (n==br){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int i=0;
    int j=0;
    while (i<n){
        if (armstrongovBroj(j)){
            printf("%d ",j);
            i++;
        }
        j++;
    }
    return 0;
}