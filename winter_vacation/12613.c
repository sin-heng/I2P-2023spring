#include<stdio.h>
#include<math.h>
long long int conc(int a,int b);
int main(void){

    int N,a,b;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d",&a,&b);
        int count=0;
        long long int tmp=0;
        for(int j=1;j<=a;j++){
            for(int k=1;k<=b;k++){
                tmp = j*k+j +k;
                if(conc(j,k)==tmp){
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
long long int conc(int a,int b){

    int tmp=b,digit=0;
    while(tmp!=0){
        tmp /= 10;
        digit++;
    }
    long long int ans = a*pow(10,digit) +b;
    return ans;
}