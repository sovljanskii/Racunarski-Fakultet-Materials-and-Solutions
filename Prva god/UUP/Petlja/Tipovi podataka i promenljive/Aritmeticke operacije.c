#include <stdio.h>

/*
Napisati program koji za dva uneta cela broja vrši operacije sabiranja, oduzimanja,
množenja, celobrojnog deljenja i ostatka pri celobrojnom deljenju.
*/

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d %d %d %d",a+b,a-b,a*b,a/b,a%b);
    return 0;
}