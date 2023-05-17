#include "function.h"
#include<stdlib.h>
#include<stdio.h>
int cmp(const void* a, const void* b){
    Node* x = *(Node**)a;
    Node* y = *(Node**)b;
    if(x->age > y->age) return 1; //a>b
    else if(x->age < y->age) return -1; // a<b
    else if(x->age == y->age && x->number < y->number) return -1; //a<b
    else if(x->age == y->age && x->number > y->number) return 1; // a>b
}
Node* createList(int n){
    Node* head = (Node*)malloc(sizeof(Node)),* cursor = head;
    int age;
    scanf("%d",&cursor->age);
    cursor->number=0;
    for(int i=1;i<n;i++){
        cursor->next = (Node*)malloc(sizeof(Node));
        cursor->next->prev = cursor;
        cursor = cursor->next;
        scanf("%d",&cursor->age);
        cursor->number = i;
        // Setting number, which represents order 
        /*
        age = cursor->age;
        cursor->number=0;
        Node* tmp = head;
        while(tmp!=cursor){
            if(age>=tmp->age)
                cursor->number++;
            else if(age<tmp->age)
                tmp->number++;
            tmp = tmp->next;
        }*/
    }
    cursor->next = head;
    head->prev = cursor;
    return head;
}
Node* solve(int n, int m){
    Node* list[500000];
    Node* cursor = head;
    int a,k;
    char dirc;
    // Store Node's address by using their number
    for(int i=0;i<n;i++){
        list[i] = cursor;
        cursor = cursor->next;
    }
    qsort(list,n,sizeof(Node*),cmp);
    // Get operation command
    while(m--){
        scanf("%d %d %c",&a,&k,&dirc);
        Node* x = list[a-1],* y = list[a-1];
        // find No.a + k node
        if(n!=1) k %= (n-1);
        // make y points to right Node 
        if(dirc=='R'){
            while(k--)
                y = y->next;
        }
        else{
            k++;
            while(k--)
                y = y->prev;
        }
        if(y == x) continue;
        // makeup the hollow
        x->next->prev = x->prev;
        x->prev->next = x->next;
        // insert
        y->next->prev = x;
        x->next = y->next;
        y->next = x;
        x->prev = y;
    }
    return list[0];
}