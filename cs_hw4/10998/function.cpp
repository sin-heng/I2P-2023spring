// 10998 - Stack 
#include "function.h"
#include<iostream>
using namespace std;
List_stack::List_stack(){
    head = tail = NULL;
}
List_stack::~List_stack(){
    while(head->nextPtr!=NULL){
        head = head->nextPtr;
        delete head->prevPtr;
    }
    delete head;
}
void List_stack::push(const int & n){
    ListNode* tmp = new ListNode(n);
    if(head==NULL) head = tail = tmp;
    else{
        tmp->prevPtr = tail;
        tail->nextPtr = tmp;
        tail = tmp;
    }
}
void List_stack::pop(){
    if(tail==NULL) return;
    else if(tail==head){
        delete tail;
        head = tail = NULL;
    }
    else{
        tail = tail->prevPtr;
        delete tail->nextPtr;
        tail->nextPtr = NULL;
    }
}
void List_stack::print(){
    ListNode* tmp = tail;
    if(tmp==NULL){return;}
    else if(tmp!=NULL){
        cout << tail->data;
        tmp = tail->prevPtr;
    }
    while(tmp!=NULL){
        cout << " " << tmp->data;
        tmp = tmp->prevPtr;
    }
}