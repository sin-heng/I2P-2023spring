#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int book_n,row;
    struct _node* right;
} Node;
Node* row[25];
int N;
Node* find_pos(int A);
void moveBook(Node* pos);
int main(void){
    char cmd1[10],cmd2[10];
    int A,B;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        row[i] = (Node*)malloc(sizeof(Node));
        row[i]->book_n = i;
        row[i]->row = i;
        row[i]->right = NULL;
    }
    while(scanf("%s",cmd1)&&cmd1!="exit"){
        scanf("%d %s %d",&A,cmd2,&B);
        if(A==B) continue;
        Node* a = find_pos(A),* b = find_pos(B),* cursor;
        if(a->row == b->row) continue;
        if(cmd1=="move"){
            moveBook(a->right);
            if(cmd2=="onto")
                moveBook(b->right);
            cursor = b;
            while(cursor->right!=NULL) cursor = cursor->right;
            cursor->right = a;
            cursor = a;
            while(cursor->right->book_n!=A) cursor = cursor->right;
            cursor->right = NULL;
        }
        else if(cmd1=="pile"){
            
        }
    }
    return 0;
}
Node* find_pos(int A){
    Node* cursor;
    for(int i=0;i<N;i++){
        cursor = row[i];
        while(cursor!=NULL)
            if(cursor->book_n == A) return cursor;
    }
}
void moveBook(Node* pos){
    Node* cursor,* tmp = cursor;
    int n;
    while(pos!=NULL){
        n = pos->book_n;
        cursor = row[n];
        while(cursor!=NULL) cursor = cursor->right;
        cursor->right = pos;
        pos->row = cursor->row;
        pos = pos->right;
        cursor->right->right = NULL;
    }
    tmp->right = NULL;
}