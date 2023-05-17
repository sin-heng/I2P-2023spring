#include<stdio.h>
int count,N,M;
int chess[9][2];
int valid(int row,int col);
void place(int row,int Q,int R);
int main(void){

    while(scanf("%d %d",&N,&M)==2){
        for(int i=0;i<9;i++)
            for(int j=0;j<2;j++)
                chess[i][j]=0;
        count=0;
        place(0,N,M);
        printf("%d\n",count);
    }
    return 0;
}
int valid(int row,int col){
    int i;
    for(i=0;i<=row-1;i++){
        if(chess[i][1] == 1 && (chess[i][0]==col || chess[i][0]==(col-row+i) || chess[i][0]==(col+row-i)))
            return 0;
        else if(chess[i][1]==2 && chess[i][0] == col)
            return 0;
    }
    return 1;
}
void place(int row,int Q,int R){
    int j;
    if(row==(N+M)){
        count++;
        return;
    }
    else{
        for(j=0;j<N+M;j++){
            if(valid(row,j)){
                if(Q>0){
                    chess[row][1] = 1;
                    chess[row][0]=j;
                    place(row+1,Q-1,R);
                }
                if(R>0){
                    chess[row][1] = 2;
                    chess[row][0]=j;
                    place(row+1,Q,R-1);
                }
            }
        }
    }
}