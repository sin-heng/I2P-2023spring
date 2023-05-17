#include<stdio.h>
#include<stdlib.h>
int main(void){

    char str[10001];
    scanf("%s",&str);
    int N,start,end,n,length;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d %d",&start,&end,&n);
        length =  end-start+1;
        n%=length;
        char* tmp = (char*)malloc(sizeof(char)*n);
        for(int i=end-n,j=0;i<end;i++,j++)
            tmp[j] = str[i];
        for(int i=end-1;i>=start-1+n;i--)
            str[i] = str[i-n];
        for(int i=start-1,j=0;j<n;i++,j++)
            str[i] = tmp[j];
        free(tmp);        
    }
    printf("%s\n",str);

    return 0;
}