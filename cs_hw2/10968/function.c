// 10968 prefix to infix
// status: accept
#include "function.h"
#include<stdio.h>
void printInfix(Node *root){
    if(root->left == NULL){
        printf("%c",root->data);
        return;
    }
    char left = root->left->data,right = root->right->data;
    if(left!='&'&&left!='|') printf("%c",left);
    else if(left=='&'||left=='|') printInfix(root->left);

    printf("%c",root->data);
    if(right!='&'&&right!='|') printf("%c",right);
    else if(right=='&'||right=='|'){ 
        putchar('(');
        printInfix(root->right);
        putchar(')');
    }
}
/*
    root
    root->left
    1) A,B,C,D
        print
    2) | &
        recur
    root->right
        the same as above
*/