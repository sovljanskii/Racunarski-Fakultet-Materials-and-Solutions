#include <stdio.h>

/*
Napisati funkciju izbaciDeljiveCifre(int a, int k) koja vraća broj 
koji se dobija kada se iz broja a izbace sve cifre koje su deljive sa k.
*/

int izbaciDeljiveCifre(int a, int k){
    int br=0,step=1;
    while (a>0){
        int c=a%10;
        if (c%k){
            br=br+c*step;
            step*=10;
        }
        a/=10;
    }
    return br;
}


int main(){

    return 0;
}