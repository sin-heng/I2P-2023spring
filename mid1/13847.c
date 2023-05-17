// 13847 - Reconstruct broken binary trees
// 2023.4.3 FIRST VERSION
// 2023.4.6 second version -- all accepted
#include<stdio.h>
#include<stdlib.h>
#define Max 3000
typedef struct _node{
    int n;
    struct _node* left,* right;
} Node;
// function
Node* build(int);
Node* createNode(int);
void freeTree(Node*);
void preorder(Node* root); // input
int find_pos(int n);
// global
int str[Max];
int Pair[Max/2][2];
int used[Max/2] = {0};
int finded[Max] = {0};
int pair;
int pos[Max];
int main(void){
    int n,head_n;
    scanf("%d",&n);
    pair = (n-1)/2;
    for(int i=0;i<n;i++){
        scanf("%d",&str[i]);
        pos[str[i]-1] = i;
    }
    for(int i=0;i<pair;i++){
        scanf("%d %d",&Pair[i][0],&Pair[i][1]);
        finded[Pair[i][0]-1] = 1;
        finded[Pair[i][1]-1] = 1;
    }
    // find head number
    for(int i=0;i<Max;i++)
        if(finded[i]!=1){
            head_n = i+1;
            break;
        }
    Node* root = build(pos[head_n-1]);
    printf("%d",root->n);
    preorder(root->left);
    preorder(root->right);
    printf("\n");
    return 0;
}
Node* build(int Index){
    Node* root = createNode(str[Index]);  
    int i,index1,index2,finded = 0;
    for(i=0;i<pair;i++){
        if(used[i]!=1){
            index1 = pos[Pair[i][0]-1];
            index2 = pos[Pair[i][1]-1];
            if(index1>index2){
                int tmp = index1;
                index1 = index2;
                index2 = tmp;
            }
            if(index1<Index && Index<index2){
                used[i] = 1;
                finded = 1;
                root->left = build(index1);
                root->right = build(index2);
            }
        }
        if(finded==1) break;
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
        printf(" %d",root->n);
        preorder(root->left);
        preorder(root->right);
    }
}
int find_pos(int n){
    int i;
    for(i=0;i<Max;i++)
        if(str[i]==n) break;
    return i;
}