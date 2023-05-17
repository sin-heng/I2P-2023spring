// 10966 infix to syntax tree
// testcase: A&B|C&D&A&B|C&D
// status: accept
#include "function.h"
#include<stdio.h>
#include<stdlib.h>
BTNode* EXPR(){ 
    char c = expr[pos--];
    BTNode* right = NULL,* root = NULL;
    // EXPR == FACTOR
    if(c != '|' && c != '&'){
        pos++;
        right = FACTOR();
    }
    c = expr[pos];
    // 1) next is op --> EXPR OP FACTOR
    // 2) next is not op --> FACTOR
    if(c == '|' || c == '&'){
        pos--;
        root = makeNode(c);
        root->left = EXPR();
        root->right = right;
    }
    else root = right;
    return root;
}
/*
    EXPR:=FACTOR|EXPR OP FACTOR
    1) EXPR == FACTOR: meet A,B,C,D,(,)
    2) EXPR == EXPR OP FACTOR
*/
BTNode* FACTOR(){
    char c = expr[pos--];
    BTNode* root = NULL;
    // 1) FACTOR == ID
    // 2) FACOTR == (EXPR)
    if(c != '(' && c != ')') root = makeNode(c);
    else if(c == ')'){
        root = EXPR();
        c = expr[pos--];
        if(c!='('){
            printf("Error occur\n");
            freeTree(root);
        }
    }
    return root;
}
/*
    FACTOR:=ID|(EXPR)
    1) FACTOR == ID: meet A,B,C,D
    2) EXPR == (EXPR): meet (,)
*/
BTNode* makeNode(char c){
    BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
    int i;
    for(i=0;i<6;i++)
        if(sym[i] == c) break;
    tmp->data = i;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}