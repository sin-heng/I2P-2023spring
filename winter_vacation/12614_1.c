#include<stdio.h>
#include<stdlib.h>
int main(void){

    int game,bill,Index=0,buy=0;
    scanf("%d %d",&game,&bill);

    int* games = (int*)malloc(sizeof(int)*game);
    int *bills = (int*)malloc(sizeof(int)*bill);

    for(int i=0;i<game;i++)
        scanf("%d",&games[i]);
    for(int i=0;i<bill;i++)
        scanf("%d",&bills[i]);

    for(int i=0;i<game;i++){
        if(bills[Index]>=games[i]){
            buy++;
            Index++;
        }
        if(Index==bill)
            break;
    }
    printf("%d\n",buy);

    free(games);
    free(bills);

    return 0;
}