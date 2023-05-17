#include<stdio.h>
char recur(int k,long long int Index);
char s1[] = "OuQ";
long long int length[51]; // record the length of k th string
int main(void){

    int k;
    long long int left,right;
    
    length[1] = 3;
    for(int i=2;i<=50;i++)
        length[i] = length[i-1]*2 +3;
    while(scanf("%d %lld %lld",&k,&left,&right)==3){
        for(long long int i=left;i<=right;i++)
            printf("%c",recur(k,i));
        printf("\n");
    }
    return 0;
}
char recur(int k,long long int Index){

    // case for k==1
    if(k==1)
        return s1[Index];
    // case for Index=0,middle,length-1
    if(Index==0) return 'O';
    else if(Index==length[k]/2) return 'u';
    else if(Index==length[k]-1) return 'Q';

    char ans;
    if(Index<length[k]/2)
        ans = recur(k-1,Index-1);
    else if(Index>length[k]/2)
        ans = recur(k-1,Index-length[k]/2-1);
    return ans;
}