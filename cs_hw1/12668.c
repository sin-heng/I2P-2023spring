#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char ch;
    struct Node* Next,* Last;
} Node;
Node* right(Node*);
Node* left(Node*);
Node* backspace(Node*);
Node* insert(Node*,char);
Node* create(Node*,char);
int main(void){

    int T,N;
    char tmp;
    scanf("%d",&T);
    while(T--){
        Node* dummy_head = (Node*)malloc(sizeof(Node));
        Node* rear;
        //initialize
        dummy_head->ch = -1;
        dummy_head->Last = NULL;
        dummy_head->Next = NULL;
        rear = dummy_head;
        scanf("%d",&N);
        getchar();
        for(int i=0;i<N;i++){
            scanf("%c",&tmp);
            if(tmp=='B')
                rear = backspace(rear);            
            else if(tmp=='R')
                rear = right(rear);
            else if(tmp=='L')
                rear = left(rear);
            else if(rear->Next==NULL)
                rear = create(rear,tmp);
            else if(rear->Next!=NULL)
                rear = insert(rear,tmp);
        }
        Node* pt = dummy_head;
        while(pt->Next!=NULL){
            pt = pt->Next;
            printf("%c",pt->ch);
            free(pt->Last);
        }
        free(dummy_head);
        printf("\n");
    }
    return 0;
}
Node* right(Node* rear){
    if(rear->Next!=NULL)
        rear = rear->Next;
    return rear;
}
Node* left(Node* rear){
    if(rear->Last!=NULL)
        rear = rear->Last;
    return rear;
}
Node* backspace(Node* head){
    if(head->ch==-1)
        return head;
    else{
        Node* Last = head->Last,*Next = head->Next;
        Last->Next = Next;
        Next->Last = Last;
        free(head);
        return Last;
    }
}
Node* insert(Node* rear,char tmp){
    Node* pt = (Node*)malloc(sizeof(Node));
    pt->Next = rear->Next;
    pt->Last = rear;
    pt->Next->Last = pt;
    rear->Next = pt;
    pt->ch = tmp;
    rear = pt;
    return rear;
}
Node* create(Node* rear,char tmp){
    rear->Next = (Node*)malloc(sizeof(Node));
    rear->Next->Last = rear;
    rear = rear->Next;
    rear->ch = tmp;
    rear->Next = NULL;
    return rear;
}