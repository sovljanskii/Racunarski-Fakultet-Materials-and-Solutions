#include <stdio.h>
#include <math.h>

/*
Napisati funkciju koja za zadati realni broj N vraća zaokruzeni broj na X (X <= 6) decimala.
Zatim napisati program koji testira tu funkciju.
*/

double toDec(double n,int dec){
    int decc=(int)pow(10,dec);
    double br = round(n*decc)/decc;
    return br;
}

int main()
{
    double n;
    int dec;
    scanf("%lf%d",&n,&dec);
    printf("%f", toDec(n,dec));
    return 0;
}