#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int value;
    struct _node* left,* right;
} Node;
Node* create_node(int value);
Node* build(int* inorder, int* preorder, int inorder_start, int inorder_end);
int verify(Node* root, int* postorder,int* arr);
void destroy(Node* root);
void postOrder(Node* root,int* arr);
int Index=0,N;
int main(void){
    int Q;
    scanf("%d",&N);
    int* inorder=(int*)malloc(sizeof(int)*N);
    int* postorder=(int*)malloc(sizeof(int)*N);
    int* preorder=(int*)malloc(sizeof(int)*N);
    int* arr=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) scanf("%d",&preorder[i]);
    for(int i=0;i<N;i++) scanf("%d",&postorder[i]);
    scanf("%d",&Q);
    while(Q--){
        for(int i=0;i<N;i++) scanf("%d",&inorder[i]);
        Node* root = build(inorder,preorder,0,N-1);
        Index=0;
        if(verify(root,postorder,arr)) printf("Yes\n");
        else printf("No\n");
        destroy(root);
    }
    free(inorder);
    free(preorder);
    free(postorder);
    free(arr);
    return 0;
}
Node* create_node(int value){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
Node* build(int* inorder, int* preorder, int inorder_start, int inorder_end){
    if(inorder_start > inorder_end) return NULL;
    if(inorder_start == inorder_end) return create_node(*preorder);
    Node* root = create_node(*preorder);
    int i;
    for(i=inorder_start;i<=inorder_end;i++) 
        if(inorder[i]==root->value) break;
    root->left = build(inorder,preorder+1,inorder_start,i-1);
    root->right = build(inorder,preorder+1+i-inorder_start,i+1,inorder_end);
    return root;
}
int verify(Node* root, int* postorder,int* arr){
    postOrder(root,arr);
    int same=1;
    for(int i=0;i<N;i++)
        if(postorder[i]!=arr[i]){
            same=0; 
            break;
        }
    return same;
}
void destroy(Node* root){
    if(root==NULL) return;
    Node* left = root->left,* right = root->right;
    free(root);
    destroy(left);
    destroy(right);
}
void postOrder(Node* root,int* arr){
    if(root!=NULL){
        postOrder(root->left,arr);
        postOrder(root->right,arr);
        arr[Index++] = root->value;
    }
}