#include<stdio.h>
int is_leap(int year);
int main(void){

    int N,y;

    scanf("%d",&N);
    while(N--){
        scanf("%d",&y);
        int leap = is_leap(y),add=0;;
        if(is_leap(y)) add+=2;
        else add+=1;
        y+=1;
        while(!(add==0 && is_leap(y)==leap)){
            if(is_leap(y)) add+=2;
            else add+=1;
            y+=1;
            if(add>=7)
                add-=7;
        }
        printf("%d\n",y);
    }
        
    return 0;
}
int is_leap(int year){

    if(year%400==0)
        return 1;
    else if(year%4==0 && year%100!=0)
        return 1;
    else 
        return 0;
}