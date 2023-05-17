// 12183 - Fairy Testing
// 2023.4.3 first version
// 2023.4.5 second version -- sample case is passed -- all aceepted
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value; // This is the value of the subtree, not the ID number
    int tokentype; // 0 for '&', 1 for '|'
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent; //pointing to the parent node
}Node;
// function
Node* build();
Node* createNode(char);
void Flip(int n); // calculate and renew value
void inorder(Node* root); // for testing
// global
Node* variable[100001]; // This array stores the pointers pointing to the tree nodes. For example, variable[0] points to the node with ID number 0.
int main(void){
    int T,var,flip,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&var,&flip);
        getchar();
        Node* root = build();
        while(flip--){
            scanf("%d",&n);
            Flip(n);
            //printf("flip finish\n");
            printf("%d\n",root->value);
        }
    }
    return 0;
}
Node* createNode(char ch){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = 0;
    if(ch=='&') tmp->tokentype = 0;
    else if(ch=='|') tmp->tokentype = 1;
    else tmp->tokentype = -1;
    tmp->leftchild = NULL;
    tmp->rightchild = NULL;
    tmp->parent = NULL;
    return tmp;
}
Node* build(){
    Node* root = NULL;
    char ch;
    scanf("%c",&ch);
    if(ch == '|' || ch == '&'){
        root = createNode(ch);
        root->leftchild = build();
        root->leftchild->parent = root;
        root->rightchild = build();
        root->rightchild->parent = root;
    }
    else if(ch == '['){
        int i;
        scanf("%d",&i);
        getchar(); // for ']'
        root = createNode('A');
        variable[i] = root;
    }
    return root;
}
void Flip(int n){
    Node* tmp = variable[n];
    if(tmp->value == 0) tmp->value = 1;
    else tmp->value = 0;
    if(tmp->parent == NULL) return;
    tmp = tmp->parent;
    int new_value=-1;
    while(new_value!=tmp->value && tmp!=NULL){
        //printf("flag\n");
        if(tmp->tokentype == 0)
            new_value = tmp->leftchild->value & tmp->rightchild->value;
        else if(tmp->tokentype == 1)
            new_value = tmp->leftchild->value | tmp->rightchild->value;
        tmp->value = new_value;
        new_value = -1;
        if(tmp->parent == NULL) break;
        tmp = tmp->parent;
        //printf("finish\n");
    }
    //printf("here\n");
}
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->leftchild);
        printf("%d ",root->tokentype);
        inorder(root->rightchild);
    }
}