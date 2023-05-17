// 13846 Reconstruct swapped binary search trees
// 2023.4.3 first version
// 2023.4.6 second version -- all accepted
#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int n;
    struct _node* left,* right;
} Node;
// function
Node* build(int,int);
Node* createNode(int);
void freeTree(Node*);
void preorder(Node* root); // input
void inorder(Node* root); // for testing
void postorder(Node* root); // output
// global
int str[100001];
int main(void){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&str[i]);
    Node* root = build(0,N-1);
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->n);
    freeTree(root);
    return 0;
}
Node* build(int start,int end){
    Node* root = createNode(str[start]);
    if(start != end){
        int Index = start+1;
        int big_first=0;
        // get Index
        if(str[Index]>str[start]){ // bigger first confront
            big_first=1;
            while(str[Index]>str[start]) Index++;
        }
        else while(str[Index]<=str[start]) Index++;
        // build children
        if(!big_first){ // smaller case
            root->left = build(start+1,Index-1);
            root->right = build(Index,end);
        }
        else{ // bigger case
            root->right = build(start+1,Index-1);
            root->left = build(Index,end);
        }
    }
    return root;
}
Node* createNode(int n){ 
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->n = n;
    return tmp;
}
void freeTree(Node* root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
void preorder(Node* root){
    if(root!=NULL){
        printf("%d ",root->n);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->n);
        inorder(root->right);
    }
}
void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->n);
    }
}