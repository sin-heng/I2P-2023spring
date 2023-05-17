#include "function.h"
#include<stdio.h>
#include<stdlib.h>
Node* ReadOneList(){
    Node* node = (Node*)malloc(sizeof(Node));
    scanf("%d",&node->size);
    getchar();
    node->data = (int*)malloc(sizeof(int)*(node->size+1));
    for(int i=1;i<=node->size;i++)
        scanf("%d",&node->data[i]);
    node->next = NULL;
    return node;
}
void PrintList(Node* cursor){
    cursor = cursor->next;
    while(cursor!=NULL){
        printf("%d",cursor->data[1]);
        for(int i=2;i<=cursor->size;i++)
            printf(" %d",cursor->data[i]);
        printf("\n");
        cursor = cursor->next;
    }
}
void Merge(Node* dummy_head, int x, int y){
    Node* prev,* m1 = dummy_head,* m2 = dummy_head;
    int size;
    int* atmp;
    while(x--){ 
        m1 = m1->next;
        if(x==1) prev = m1;
    }
    while(y--) m2 = m2->next;
    size = m1->size+m2->size;
    atmp = (int*)malloc(sizeof(int)*(size+1));
    for(int i=1;i<=m2->size;i++) atmp[i] = m2->data[i];
    for(int i=m2->size+1,j=1;j<=m1->size;i++,j++) atmp[i] = m1->data[j];
    m2->size = size;
    free(m2->data);
    m2->data = atmp;
    prev->next = m1->next;
    free(m1->data);
    free(m1);
}
void Cut(Node* dummy_head, int x, int y){
    Node* c1 = dummy_head,* c2 = (Node*)malloc(sizeof(Node));
    int* atmp;
    while(x--) c1 = c1->next;
    c2->next = c1->next;
    c1->next = c2;
    c2->size = c1->size-y;
    c2->data = (int*)malloc(sizeof(int)*(c2->size+1));
    for(int i=1,j=y+1;i<=c2->size;i++,j++) c2->data[i] = c1->data[j];
    atmp = (int*)malloc(sizeof(int)*(y+1));
    for(int i=1;i<=y;i++) atmp[i] = c1->data[i];
    c1->size = y;
    free(c1->data);
    c1->data = atmp;
}