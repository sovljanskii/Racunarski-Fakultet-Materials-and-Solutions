#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int sum=0;
    int max=0;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            sum+=a[j];
            if (sum>max) max=sum;
        }
        sum=0;
    }

    printf("%d",max);
    return 0;
}