//Happy New Year
//finish!!
#include<stdio.h>
#include<limits.h>
int main(void){

    int N,Bob,tmp;

    scanf("%d",&N);
    scanf("%d",&Bob);

    int Min=Bob,Max=Bob;

    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        if(tmp>Max)
            Max = tmp;
        else if(tmp<Min)
            Min = tmp;
    }
    printf("%d\n",2*(Max - Min));
    return 0;
}