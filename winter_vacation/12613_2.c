#include<stdio.h>
int main(void){

    int T;
    long long int A,B;
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&A,&B);
        int digit=0;
        long long int tmp=B;
        while(tmp!=0){
            tmp/=10;
            digit++;
        }
        printf("%lld\n",(digit-1)*A);
    }
    return 0;
}