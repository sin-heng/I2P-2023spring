// two dummy Node version
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char ch;
    struct Node* Next,* Last;
} Node;
Node* right(Node*);
Node* left(Node*);
Node* backspace(Node*);
int main(void){

    int T,N;
    char tmp;
    scanf("%d",&T);
    while(T--){
        Node* head = (Node*)malloc(sizeof(Node)),* tail = (Node*)malloc(sizeof(Node));
        Node* cursor;
        //initialize
        head->ch = -1;
        head->Last = NULL;
        head->Next = tail;
        tail->Last = head;
        tail->ch = -1;
        cursor = head;
        scanf("%d",&N);
        getchar();
        for(int i=0;i<N;i++){
            scanf("%c",&tmp);
            if(tmp=='B')
                cursor = backspace(cursor);            
            else if(tmp=='R')
                cursor = right(cursor);
            else if(tmp=='L')
                cursor = left(cursor);
            else{
                Node* pt = (Node*)malloc(sizeof(Node));
                pt->Next = cursor->Next;
                pt->Last = cursor;
                pt->Next->Last = pt;
                cursor->Next = pt;
                pt->ch = tmp;
                cursor = pt;
            }
        }
        Node* pt = head;
        while(pt->Next->ch!=-1){
            pt = pt->Next;
            printf("%c",pt->ch);
            free(pt->Last);
        }
        free(tail);
        printf("\n");
    }
    return 0;
}
Node* right(Node* cursor){
    if(cursor->Next!=NULL)
        cursor = cursor->Next;
    return cursor;
}
Node* left(Node* cursor){
    if(cursor->Last!=NULL)
        cursor = cursor->Last;
    return cursor;
}
Node* backspace(Node* cursor){
    if(cursor->ch==-1)
        return cursor;
    else{
        Node* Last = cursor->Last,*Next = cursor->Next;
        Last->Next = Next;
        Next->Last = Last;
        free(cursor);
        return Last;
    }
}