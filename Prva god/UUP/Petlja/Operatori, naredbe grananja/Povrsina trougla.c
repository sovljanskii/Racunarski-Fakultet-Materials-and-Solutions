#include <stdio.h>

/*
Napisati program koji za učitane vrednosti kateta dva pravougla trougla,
ispisuje koji trougao ima veću površinu.
*/

int main(){
    int a1,b1,a2,b2;
    scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
    float p1=a1*b1/2.0;
    float p2=a2*b2/2.0;
    if (p1>p2){
        printf("1");
    }
    else if (p1<p2){
        printf("2");
    }
    else printf("0");
    return 0;
}