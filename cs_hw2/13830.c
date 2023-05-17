// testcase1: -+AB*CD
// testcase2: *+AB-C+DE
// status: 
#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    char ch;
    struct _node* left,* right;
} Node;
Node* buildTree();
void printInfix(Node*);
Node* createNode(char c);
void Traverse(Node*); // debug purpose
char str[257];
int Index=0;
int main(void){
    scanf("%s",str);
    Node* root = buildTree();
    //Traverse(root); debug for build tree
    printInfix(root);
    printf("\n");
    return 0;
}
Node* buildTree(){
    char ch = str[Index];
    Node* nd = createNode(ch);
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        Index++;
        nd->left = buildTree();
        nd->right = buildTree();
    }
    else
        Index++;
    return nd;
}
void printInfix(Node* root){
    if(root->left == NULL){
        printf("%c",root->ch);
        return;
    }
    char head = root->ch, left = root->left->ch,right = root->right->ch;
    // left 
    // if left is operator and priority lower than root
    if((left=='+'||left=='-')&&(head=='*'||head=='/')){
        putchar('(');
        printInfix(root->left);
        putchar(')');
    }
    // left is A~Z
    else if(left>=65&&left<=90) printf("%c",left);
    // other case is left is operator
    else printInfix(root->left);
    
    // root
    printf("%c",head);
    // right(same as left)
    if((right=='+'||right=='-')&&(head=='-')){
        putchar('(');
        printInfix(root->right);
        putchar(')');
    }
    else if((head=='*'||head=='/')&&!(right=='*'&&head=='*')&&!(65<=right&&right<=90)){
        putchar('(');
        printInfix(root->right);
        putchar(')');
    }
    else if(65<=right&&right<=90) printf("%c",right);
    else printInfix(root->right);
    /*
        parenthesis:
            1) head: +, right: 
            2) head: -, right: +-
            3) head: *, right: +-/
            4) head: /, right: +-/*
    */
}
Node* createNode(char c){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->ch = c;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
void Traverse(Node* root){
    if(root!=NULL){
        Traverse(root->left);
        printf("%c",root->ch);
        Traverse(root->right);
    }
}