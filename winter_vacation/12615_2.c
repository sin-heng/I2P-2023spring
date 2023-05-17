#include<stdio.h>
#include<string.h>
#include<math.h>
char str[] = "ICPCASIASG";
void recur(int x,int y,int n);
char chess[100][100];
int N;
int ans=0;
int main(void){

    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            scanf("%c",&chess[i][j]);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(chess[i][j]==str[0])  
                recur(i,j,1);

    if(ans == 0)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
void recur(int x,int y,int n){

    if(n==strlen(str)){
        ans=1;
        return;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(chess[i][j] == str[n] && (pow(x-i,2)+pow(y-j,2)==5))
                recur(i,j,n+1);
}