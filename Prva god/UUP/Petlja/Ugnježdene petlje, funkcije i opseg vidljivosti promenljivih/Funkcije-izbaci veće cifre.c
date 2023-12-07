#include <stdio.h>

int izbaciVeceCifre(int a, int k){
    int br=0,step=1;
    while (a>0){
        int c=a%10;
        if (c<=k){
            br=br+c*step;
            step*=10;
        }
        a/=10;
    }
    return br;
}
