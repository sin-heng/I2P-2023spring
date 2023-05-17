#include<stdio.h>
#include<limits.h>
int main(void){

    char dirc[200001];
    int posi[200000];
    int N,min=INT_MAX;
    scanf("%d %s",&N,dirc);
    for(int i=0;i<N;i++) scanf("%d",&posi[i]);
    for(int i=0;i<N-1;i++)
        if(dirc[i]=='R' && dirc[i+1]=='L')
            if((posi[i+1]-posi[i])/2 < min)
                min = (posi[i+1]-posi[i])/2;

    if(min == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n",min);
    return 0;
}