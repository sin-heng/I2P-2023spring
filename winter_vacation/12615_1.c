#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int recur(int x,int y,int n);
const char str[] = "ICPCASIASG";
int N;
char chess[100][100];
int main(void){

    int ans=0;
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%c",&chess[i][j]);
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(chess[i][j]==str[0])
                ans = recur(i,j,1);
    if(ans==1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
int recur(int x,int y,int n){

    int ans=0;
    if(n==strlen(str))
        return 1;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(chess[i][j]==str[n] && (pow(x-i,2)+pow(y-j,2)==5))
                ans = recur(i,j,n+1);
    
    return ans;
}