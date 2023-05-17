#include<stdio.h>
int main(void){

    int n,m;
    char str[200001];
    char x,y;
    char alphabet[26];

    for(int i=0;i<26;i++)
        alphabet[i] = 97+i;

    scanf("%d %d",&n,&m);
    scanf("%s",str);
    while(m--){
        getchar();
        scanf("%c %c",&x,&y);
        if(x==y)
            continue;
        int l,r;
        for(int i=0;i<26;i++){
            if(alphabet[i] == x)
                l = i;
            else if(alphabet[i] == y)
                r = i;
        }
        char tmp = alphabet[l];
        alphabet[l] = alphabet[r];
        alphabet[r] = tmp;
    }
    for(int i=0;i<n;i++)
        printf("%c",alphabet[str[i]-97]);
    printf("\n");
    return 0;
}