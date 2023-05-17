#include<stdio.h>
#include<stdlib.h>
int main(void){

    int n,Bob;

    scanf("%d",&n);
    scanf("%d",&Bob);
    int min=Bob,max=Bob;

    int* posi = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&posi[i]);
        if(posi[i]>max)
            max = posi[i];
        else if(posi[i]<min)
            min = posi[i];
    }
    printf("%d\n",(max-min)*2);
    return 0;
}