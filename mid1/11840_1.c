// using linked list
// all accepted
#include<stdio.h>
#include<stdlib.h>
#define MAX 25
typedef struct _stack{
    int* bookcase;
    int cap; // capacity
} Stack;
void push(int i,int val);
void pop(int i);
void move(int* pos);
void find_pos(int* pos,int i);
Stack book[25];
int posA[2],posB[2];
int N;
int main(void){
    char cmd1[10],cmd2[10];
    int A,B;
    scanf("%d",&N);
    // initialize
    for(int i=0;i<N;i++){
        book[i].bookcase = (int*)malloc(sizeof(int)*MAX);
        book[i].cap = 0;
        push(i,i);
    }
    while(scanf("%s",cmd1)&&cmd1[0]!='e'){
        scanf("%d %s %d",&A,cmd2,&B);
        if(A==B) continue;
        find_pos(posA,A);find_pos(posB,B);
        if(posA[0]==posB[0]) continue;
        // move->remove A, onto->remove B
        // all put A on B
        if(cmd2[1]=='n') // onto
            move(posB);
        if(cmd1[0]=='m'){ // move
            move(posA);
            push(posB[0],A);
            pop(posA[0]);
        }
        else{ // pile
            for(int i=posA[1];i<book[posA[0]].cap;i++)
                push(posB[0],book[posA[0]].bookcase[i]);
            for(int i=book[posA[0]].cap-1;i>=posA[1];i--)
                pop(posA[0]);
        }
    }
    // print
    for(int i=0;i<N;i++){
        printf("%d:",i);
        for(int j=0;j<book[i].cap;j++)
            printf(" %d",book[i].bookcase[j]);
        printf("\n");
        free(book[i].bookcase);
    }
    return 0;
}
void push(int i,int val){
    if(book[i].cap==MAX) printf("Stack full\n");
    book[i].bookcase[book[i].cap++] = val;
}
void pop(int i){
    if(book[i].cap==-1) printf("Stack empty\n");
    book[i].bookcase[--book[i].cap]=0;
}
void move(int* pos){
    for(int i=book[pos[0]].cap-1;i>pos[1];i--){
        push(book[pos[0]].bookcase[i],book[pos[0]].bookcase[i]);
        pop(pos[0]);
    }
}
void find_pos(int* pos,int val){
    for(int i=0;i<N;i++){
        for(int j=0;j<book[i].cap;j++)
            if(book[i].bookcase[j]==val){
                pos[0]=i;pos[1]=j;
                return;
            }
    }
}