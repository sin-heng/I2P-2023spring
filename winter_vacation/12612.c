#include<stdio.h>
#include<string.h>
int main(void){

    char str[10001];
    scanf("%s",&str);
    int N,start,end,n,length;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d %d",&start,&end,&n);
        length =  end-start+1;
        n%=length;
        for(int i=0;i<length/2;i++){
            
        }
        printf("%s",str);
        
    }

    return 0;
}