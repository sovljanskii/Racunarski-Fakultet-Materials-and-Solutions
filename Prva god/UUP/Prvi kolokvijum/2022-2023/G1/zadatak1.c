#include <stdio.h>
#include <math.h>


int prost(int n){
    if (n==2) return 1;
    for (int i=2;i<n;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
int nadjiprostbr(int n){
    int x=0;
    int prostbr=2;
    int i=2;
    while(x<n){
        if (prost(i)){
            x++;
            prostbr=i;
        }
        i++;
    }
    return prostbr;

}

int pom(int args){
    int max=0;
    int brojcifri=0;
    int rez=args;
    while (rez!=0){
        brojcifri++;
        rez/=10;
    }
    brojcifri--;
    while (args!=0){
        if (args>10){
        int a= args/pow(10,brojcifri--);


        int b=args%10;

        int zbir= a+b;

        if (prost(zbir)){
            if (zbir>max)max=zbir;
        }

        args/=10;
        args=args%(int)pow(10,brojcifri);
        brojcifri--;
            }
        else {
            if (prost(args)){
                if (args>max)max=args;
            }
            break;
        }
    }

    int k= nadjiprostbr(max);
    return k;
}
int okreni(int br,int n){
    int rez=br;
    int brcifri=0;
    while (rez!=0){
        brcifri++;
        rez/=10;
    }
    for (int i=0;i<n;i++){
        int x=br%10;
        br/=10;
        br=x*(int)pow(10,brcifri-1)+br;
    }
    return br;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        printf("%d\n", okreni(n, pom(n)));
        scanf("%d",&n);
    }

    return 0;
}