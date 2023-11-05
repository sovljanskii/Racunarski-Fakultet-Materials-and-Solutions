#include <stdio.h>

/*
Napisati funkciju koja za zadata tri prirodna broja vraca 1 ako može da se formira trougao od tih duzina, 
ili 0 ako ne može. Potom napisati program koji testira tu funkciju.
*/

int trougao(int a,int b,int c){
    if (a+b>c && a+c>b && b+c>a){
        return 1;
    }
    return 0;
}

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if (trougao(a,b,c)){
        printf("moze");
    }
    else printf("ne moze");
    return 0;
}