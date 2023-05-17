// 11847 prefix boolean expression
// testcase: |&AC|AB
// status: all accept
#include<stdio.h>
int evalBoolExpr();
int val[5]={0};
char str[31];
int cursor;
int main(void){
    int ans;
    scanf("%s",str);
    for(int i=0;i<16;i++){
        // reset cursor
        cursor = 0;
        ans = evalBoolExpr();
        // print truth table
        printf("%d",val[1]);
        for(int i=2;i<5;i++) printf(" %d",val[i]);
        printf(" %d\n",ans);
        // renew truth table's input value
        val[4]++;
        for(int i=4;i>0;i--)
            if(val[i]>=2){
                val[i]-=2;
                val[i-1]++;
            }
    }
    return 0;
}
int evalBoolExpr(){
    char c = str[cursor];
    if(c == '|' || c == '&'){
        int op1,op2;
        op1 = evalBoolExpr(++cursor);
        op2 = evalBoolExpr(++cursor);
        if(c=='|') return op1 | op2;
        else return op1 & op2;
    }
    else return val[(int)c-64];
}
// | & A C | A B
// 0 1 2 3 4 5 6
/*
    first recur: cursor=0, c=='|', op1 = jump to second
    second recur: cursor=1, c=='&', op1 = jump to third
    third recur: cursor=2, c=='A', back to second
    second recur: op1 = third recur, op2 = jump to fourth
    fourth recur: cursor=3, back to second  
    second recur: back to first
    first recur: op1 = second recur, op2 = jump to fifth
    fifth recur:
*/