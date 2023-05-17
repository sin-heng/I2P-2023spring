#include<stdio.h>
#include<string.h>
#include<math.h>
char str[] = "ICPCASIASG";
int chess[100][100];
int count,N;
void recur(int x,int y,int n);
int main(void){

    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%c",&chess[i][j]);
    count=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(chess[i][j]==str[0])
                recur(i,j,1);
    if(count==0)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
void recur(int x,int y,int n){

    if(n==strlen(str)){
        count++;
        return;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(chess[i][j]==str[n] && pow(x-i,2) + pow(y-j,2)==5)
                recur(i,j,n+1);
}