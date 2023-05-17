#include<stdio.h>
#include<limits.h>
int main(void){

    char dirc[200001];
    int posi[200001];
    int n,min=INT_MAX,count=0;

    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
        scanf("%c",&dirc[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&posi[i]);

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++){
            if(dirc[i]=='L' && dirc[j]=='R' && (posi[i] > posi[j])){
                if(posi[i]-posi[j] < min)
                    min = posi[i]-posi[j];
                count++;
            }
            else if(dirc[i]=='R' && dirc[j]=='L' && (posi[i] < posi[j])){
                if(posi[j]-posi[i] < min)
                    min = posi[j]-posi[i];
                count++;
            }
        }
    if(count==0)
        printf("-1\n");
    else    
        printf("%d\n",min/2);
    return 0;
}