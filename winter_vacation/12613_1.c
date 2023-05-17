#include<stdio.h>
#include<math.h>
int main(void){

    int N,a,b;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d",&a,&b);
        int tmp=b,digit=0;
        while(tmp!=0){
            tmp/=10;
            digit++;
        }
        printf("%lld\n",(digit-1)*a);
    }
    return 0;
}
