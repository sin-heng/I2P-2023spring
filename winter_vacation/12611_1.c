#include<stdio.h>
int is_leap(int y);
int main(void){

    int n,year;

    scanf("%d",&n);
    while(n--){
        scanf("%d",&year);
        int add=0;
        int leap = is_leap(year);
        if(leap==1) add+=2;
        else add+=1;
        year+=1;
        while(!(add==0 && is_leap(year)==leap)){
            if(is_leap(year)) add+=2;
            else add+=1;
            year+=1;
            if(add>=7)
                add-=7;
        }
        printf("%d\n",year);            
    }
}
int is_leap(int y){
    if(y%4==0 && y%100!=0)
        return 1;
    else if(y%400==0)
        return 1;
    return 0;
}