#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int recur(int x,int y,int n);
const char str[] = "ICPCASIASG";
int N;
char chess[100][100];
int main(void){

    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%c",&chess[i][j]);
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(chess[i][j]=='I')
                ans += recur(i,j,0);
    if(ans >= 1)
        printf("YES\n");
    else if(ans==0)
        printf("NO\n");
    return 0;
}
int recur(int x,int y,int n){

    int ans=0;
    if(chess[x][y] == str[n] &&n==(strlen(str)-1))
        return 1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if((pow(x-i,2) + pow(y-j,2)) == 5 && chess[i][j] == str[n])
                ans += recur(i,j,n+1);
            else if((pow(x-i,2) + pow(y-j,2)) == 5 && chess[i][j] != str[n])
                ans += 0;
            else 
                continue;
        }
    }
    return ans;
}