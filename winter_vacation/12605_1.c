#include<stdio.h>
#include<stdlib.h>
int main(void){

    int length,n;
    char alphabet[26];
    char x,y;
    int i1,i2;

    scanf("%d %d",&length,&n);
    char* str = (char*)malloc(sizeof(char)*(length+1));
    scanf("%s",str);

    for(int i=0;i<26;i++)
        alphabet[i] = 97+i;
    
    while(n--){
        getchar();
        scanf("%c %c",&x,&y);
        if(x==y)
            continue;
        for(int i=0;i<26;i++){
            if(alphabet[i]==x)
                i1 = i;
            if(alphabet[i]==y)
                i2=i;
        }
        char tmp = alphabet[i1];
        alphabet[i1] = alphabet[i2];
        alphabet[i2] = tmp;
    }

    for(int i=0;i<length;i++){
        printf("%c",alphabet[str[i]-97]);
    }
    printf("\n");
    free(str);
    return 0;
}