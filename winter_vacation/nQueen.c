#include<stdio.h>
int NQ,count=0;
int q[100];
int valid(int row,int col){
    int i;
    for(i=0;i<=row-1;i++){
        if(q[i]==col || q[i]==(col-row+i) || q[i]==(col+row-i))
            return 0;
    }
    return 1;
}
void place(int row){
    int j;
    if(row==NQ){
        count++;
        return;
    }
    else{
        for(j=0;j<NQ;j++){
            if(valid(row,j)){
                q[row]=j;
                place(row+1);
            }
        }
    }
}
int main(){

    scanf("%d",&NQ);
    place(0);
    printf("%d\n",count);
    return 0;
}