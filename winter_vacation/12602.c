#include<stdio.h>
#include<string.h>
char s1[] = "OuQ";
char find_char(int n,int k);
int length[51];
int main(void){

    int k,l,r;
    length[1] = 3;
    for(int i=2;i<51;i++)
        length[i] = 2*length[i-1] + 3;

    while(scanf("%d %d %d",&k,&l,&r)==3){
        for(int i=l;i<=r;i++)
            printf("%c",find_char(i,k));
        printf("\n");
    }
    
    return 0;
}
char find_char(int n,int k){

    char ans;
    if(k==1)
        ans = s1[n];
    else if(n==0)
        ans = 'O';
    else if(n==length[k]/2)
        ans = 'u';
    else if(n==length[k]-1)
        ans = 'Q';
    else if(n<length[k]/2)
        ans = find_char(n-1,k-1);
    else if(n>length[k]/2)
        ans = find_char(n-length[k]/2-1,k-1);
    return ans;
}