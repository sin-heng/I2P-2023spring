#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int order,age;
    struct Node* last,* next;
} Node;
void clock(Node*,int,int);
void cclock(Node*,int,int);
int main(void){

    int N,M,A,K,order=1;
    char dirc;

    scanf("%d %d",&N,&M);
    // record
    int* age = (int*)malloc(sizeof(int)*N);
    // dual linked list
    Node* head = (Node*)malloc(sizeof(Node)),* cursor = head;
    scanf("%d",&cursor->age);
    age[0] = cursor->age;
    cursor->order = order;
    for(int i=1;i<N;i++){
        order=1;
        cursor->next = (Node*)malloc(sizeof(Node));
        scanf("%d",&age[i]);
        cursor->next->age = age[i];
        cursor->next->last = cursor;
        cursor = cursor->next;
        for(int j=0;j<i;j++){
            if(age[i]>=age[j])
                order++;
            else{
                Node* tmp = cursor;
                int itmp = i-j;
                while(itmp--)
                    tmp = tmp->last;
                tmp->order++;
            }
        }
        cursor->order = order;
    }
    head->last = cursor;
    cursor->next = head;
    // operation
    while(M--){
        scanf("%d %d %c",&A,&K,&dirc);
        K %= (N-1);
        if(dirc=='R')
            clock(head,A,K);
        else
            cclock(head,A,K);
    }
    cursor = head;
    while(cursor->order!=1)
        cursor = cursor->next;
    printf("%d",cursor->age);
    Node* start = cursor;
    cursor = cursor->next;
    while(cursor!=start->last){
        printf(" %d",cursor->age);
        cursor = cursor->next;
        free(cursor->last);
    }
    printf(" %d",cursor->age);
    free(cursor);
    printf("\n");
    return 0;
}
void clock(Node* head,int A,int K){
    Node* X,* Y;
    while(head->order!=A)
        head = head->next;
    X = head;
    while(K--)
        head = head->next;
    Y= head;

    X->next->last = X->last;
    X->last->next = X->next;
    Y->next->last = X;
    X->next = Y->next;
    Y->next = X;
    X->last = Y;
}
void cclock(Node* head,int A,int K){
    Node* X,* Y;
    while(head->order!=A)
        head = head->next;
    X = head;
    while(K--)
        head = head->last;
    Y= head;

    X->next->last = X->last;
    X->last->next = X->next;
    Y->last->next = X;
    X->last = Y->last;
    Y->last = X;
    X->next = Y;
}