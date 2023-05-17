#include<stdio.h>
#include "function.h"
#include<stdlib.h>

void deleteNode(Node ** nd, int data){

    Node* head = *nd;
    Node* Last = head;
    head = Last->next;

    if(data==1){
        free(Last);
        *nd = head;
    }
    else{
        data-=2;
        while(data--){
            Last = head;
            head = Last->next;
            if(head==NULL)
                return;
        }
        Last->next = head->next;
        free(head);
    }
}
Node* createList(){

    Node* head = (Node*)malloc(sizeof(Node));
    Node* cp_head = head;
    scanf("%d",&head->data);
    head->next = NULL;

    int itmp;
    while(scanf("%d",&itmp) && itmp!=-1){
        head->next = (Node*)malloc(sizeof(Node));
        head = head->next;
        head->data = itmp;
        head->next = NULL;
    }
    return cp_head;
}