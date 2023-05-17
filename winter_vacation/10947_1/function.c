#include<stdio.h>
#include "function.h"
#include<stdlib.h>

void deleteNode(Node ** nd, int data){

    Node* Last,*head = *nd;
    Last = head;
    head = head->next;

    if(data==1){
        free(Last);
        *nd = head;
    }
    else{
        data-=2;
        while(data--){
            Last = head;
            head=head->next;
            if(head==NULL)
                return;
        }
        Last->next = head->next;
        free(head);
    }
}
Node* createList(){

    Node* head = (Node*)malloc(sizeof(Node));
    Node* copy = head;

    scanf("%d",&head->data);
    head->next = NULL;
    int tmp;
    while(scanf("%d",&tmp) && tmp!=-1){
        head->next = (Node*)malloc(sizeof(Node));
        head = head->next;
        head->data = tmp;
    }
    head->next = NULL;
    return copy;
}