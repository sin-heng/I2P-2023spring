// 13149 - Ternary Expression Evaluation
// 2023.4.4 first version
// 2023.4.5 second version -- sample case passed -- pass three cases -- all accepted
#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int n;
    struct _node* left,* right;
} Node;
// function
Node* expres();
int cal(Node* root);
// global
char val[3002];
int main(void){
    int T;
    Node* root = expres();
    scanf("%d",&T);
    while(T--){
        scanf("%s",val);
        printf("%d\n",cal(root));
    }
    return 0;
}
Node* expres(){
    Node* root = (Node*)malloc(sizeof(Node));
    root->left = root->right = NULL;
    scanf("%d",&root->n);

    char ch;
    scanf("%c",&ch);

    if(ch == '?'){
        root->left = expres();
        root->right = expres();
    }
    return root;
}
int cal(Node* root){
    if(root->left == NULL) return (int)val[root->n-1]-48;
    if(val[root->n-1]=='1') return cal(root->left);
    else return cal(root->right);
}