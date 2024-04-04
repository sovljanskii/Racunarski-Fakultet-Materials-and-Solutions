#include <stdio.h>
/*
Napisati funkciju prostBroj(int a) koja vraća 1 ukoliko je broj a prost, a 0 ukoliko je broj a složen.
*/
int prostBroj(int a){
    for (int i=2;i<=a/2;i++){
        if (a%i==0){
            return 0;
        }
    }
    return 1;
}