#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct _node{
    int data;
    struct _node* left,* right;
} BTNode;
BTNode* createTree();
BTNode* createNode(int);
void find_posi(BTNode*,int);
int find_path(BTNode*,char*,int,int);
void com(char*,char*);
void freeTree(BTNode*);
BTNode* cursor = NULL;
char a[3000]={0},b[3000]={0};
int main(void){

    BTNode* head = createTree();
    int N,x,y;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d",&x,&y);
        find_path(head,a,0,x);
        find_path(head,b,0,y);
        com(a,b);
        printf("\n");
        for(int i=0;i<3000;i++)
            a[i] = b[i] = 0;
    }
    freeTree(head);
    return 0;
}
BTNode* createTree(){
    BTNode* head = createNode(1);
    cursor = head;
    int N,x,y;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        find_posi(head,i);
        scanf("%d %d",&x,&y);
        if(x!=0){
            cursor->left = createNode(x);
        }else cursor->left = NULL;
        if(y!=0){
            cursor->right = createNode(y);
        }else cursor->right = NULL;
    }
    return head;
}
BTNode* createNode(int n){
    BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
    tmp->data = n;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
void find_posi(BTNode* head,int n){
    if(head == NULL) return;
    if(head->data == n){
        cursor = head;
        return;
    }
    find_posi(head->left,n);
    find_posi(head->right,n);
}
int find_path(BTNode* head,char* c,int index,int n){
    if(head == NULL) return 0;
    if(head->data == n) return 1;
    int ans = find_path(head->left,c,index+1,n);
    if(ans==0){
        ans = find_path(head->right,c,index+1,n);
        if(ans) c[index] = 'R';
        return ans;
    }else c[index] = 'L';
    return ans;
}
void com(char* a,char* b){
    int j=0;
    bool same = true;
    for(int i=0;i<3000;i++){
        if(a[i] != 'L' && a[i] != 'R') break;
        if(a[i]!=b[i] || same == false){
            putchar('P');
            same = false;
        }else if(same) j++;
    }
    for(;j<3000;j++){
        if(b[j] != 'L' && b[j] != 'R') break;
        printf("%c",b[j]);
    }
}
void freeTree(BTNode* head){
    if(head==NULL) return;
    BTNode* left = head->left,* right = head->right;
    free(head);
    freeTree(left);
    freeTree(right);
}