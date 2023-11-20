#include <stdio.h>
#include <math.h>

int swap(int arg,int x,int y){
    int poz=1;
    int br=0;
    int stepen=1;
    while (arg){
        int c = arg%10;
        if (poz==x){
            br=br+c*(int)pow(10,y-1);


        }
        else if (poz==y){
            br=br+c*(int)pow(10,x-1);

        }
        else {
            br=br+c*stepen;

        }

        poz++;
        stepen*=10;
        arg/=10;

    }
    return br;
}

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    for (int i=a;i<=b;i++){
        if (i>swap(i,1,3))  {
            printf("%d ",i);
        }
    }
    return 0;
}
