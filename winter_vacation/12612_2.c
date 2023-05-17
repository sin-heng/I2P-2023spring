#include<stdio.h>
#include<stdlib.h>
int main(void){

    char str[10001];
    int m,l,r,k;

    scanf("%s",str);
    scanf("%d",&m);

    while(m--){
        scanf("%d %d %d",&l,&r,&k);
        int length = r-l+1;
        k%=length;
        char* tmp = (char*)malloc(sizeof(char)*k);
        for(int i=r-k,j=0;i<r;i++,j++)
            tmp[j] = str[i];
        for(int i=r-1;i>=l-1;i--)
            str[i] = str[i-k];
        for(int i=l-1,j=0;i<l-1+k;i++,j++)
            str[i] = tmp[j];
        free(tmp);
    }
    printf("%s\n",str);

    return 0;
}