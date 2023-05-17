#include "function.h"
#include<stdlib.h>
#include<stdio.h>
void reverse(Node *node_l, Node *node_r){

    if(node_l->next==node_r)
        return;
    Node* cursor = node_l->next;
    Node* last  = node_r->next,* next = cursor->next;
    // first position point to tail
    while(cursor!=node_r){
        cursor->next = last;
        // renew
        last = cursor;
        cursor = next;
        next = cursor->next;
    }
    cursor->next = last; // cursor == node_r
    // put head to the lastest position
    node_l->next = cursor;
}