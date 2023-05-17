#include<stdio.h>
int main(void){

    int cost[1000],bill[1000];
    int n,m,count=0,Indexb=0;

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&cost[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&bill[i]);

    for(int i=0;i<n;i++){
        if(cost[i]<=bill[Indexb]){
            count++;
            Indexb++;
        }
        if(Indexb==m)
            break;
    }
    printf("%d\n",count);

    return 0;
}