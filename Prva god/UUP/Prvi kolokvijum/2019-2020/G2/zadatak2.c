#include <stdio.h>

int main(){
    char c;
    int zapocet_tag=0;
    int a=0,b=0;
    int greska=0;
    while ((c= getchar())!='\n'){
        switch (c) {
            case '<':
                zapocet_tag = 1;
                break;
            case '>':
                if (zapocet_tag==2) {

                }
                zapocet_tag = 0;
                break;
            case 'a':
                if (zapocet_tag==1) {
                    a+=b+1;
                }
                else if (zapocet_tag==2){
                    if (a<b){
                        greska=1;
                        break;
                    }
                    else {
                        a=0;
                    }
                }
                break;
            case 'b':
                if (zapocet_tag==1) {
                    b+=a+1;
                }
                else if (zapocet_tag==2){
                    if (b<a){
                        greska=1;
                        break;
                    }
                    else {
                        b=0;

                    }
                }
            case '/':
                if (zapocet_tag) {
                    zapocet_tag=2;
                }
                break;
        }
        if (greska){
            printf("greska");
            break;
        }
    }
    if (!greska && a==0&&b==0) printf("ok");
    else if (!greska) printf("greska");
    return 0;
}
