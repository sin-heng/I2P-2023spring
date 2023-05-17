#include "function.h"
#include<stdlib.h>
#include<stdio.h>
Node* ReadOneList(){
    int N;
    scanf("%d",&N);
    //setting new Node
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->size = N;
    tmp->data = (int*)malloc(sizeof(int)*N);
    //get data
    getchar();
    for(int i=0;i<N;i++)
        scanf(" %d",&(tmp->data)[i]);
    tmp->next = NULL;
    return tmp;
}
void PrintList(Node* head){
    head = head->next; //move from dummy to 1
    while(head!=NULL){
        printf("%d",head->data[0]);
        for(int i=1;i<head->size;i++)
            printf(" %d",(head->data)[i]);
        printf("\n");
        head = head->next;
    }
}
void Merge(Node* head, int x, int y){

    Node* tmp = head,* Last; //last to remember the position where node will gone 
    //move to the right stack position
    for(int i=0;i<y;i++)
        head = head->next;
    for(int i=0;i<x;i++){
        if(i==x-1)
            Last = tmp;
        tmp = tmp->next;
    }
    // copy data
    int size = head->size + tmp->size;
    int* itmp = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<head->size;i++)
        itmp[i] = (head->data)[i];
    for(int j=head->size,i=0;j<size;j++,i++)
        itmp[j] = (tmp->data)[i];
    free(head->data);
    head->data = itmp;
    head->size = size;
    Last->next = tmp->next;
    free(tmp->data);
    free(tmp);
}
void Cut(Node* head, int a, int b){

    for(int i=0;i<a;i++) //move the target stack
        head = head->next;
    
    //create new Node
    Node* new = (Node*)malloc(sizeof(Node));
    new->size = head->size -b;
    new->data = (int*)malloc(sizeof(int)*new->size);
    for(int i=b,j=0;i<head->size;i++,j++)
        (new->data)[j] = head->data[i];
    
    //renew original stack
    int* itmp = (int*)malloc(sizeof(int)*b);
    for(int i=0;i<b;i++)
        itmp[i] = (head->data)[i];
    free(head->data);
    head->data = itmp;
    head->size = b;
    Node* Next = head->next;
    head->next = new;
    new->next = Next;
}