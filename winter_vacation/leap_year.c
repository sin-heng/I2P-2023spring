#include<stdio.h>
int is_leap(int year){

    if(year%400==0)
        return 1;
    else if(year%4==0 && year%100!=0)
        return 1;
    else 
        return 0;
}
int main(void){

    int itmp;
    while(scanf("%d",&itmp)){
        if(is_leap(itmp))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}