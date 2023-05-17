#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    char ch;
    struct _node* left,* right;
} Node;
// function
long long Mod(long long num);
long long cal(Node* root);
Node* build();
Node* create(char c);
void traverse(Node* root);
// variable
char str[26][201];
long long num[5];
Node* func[26];
int nfunc,pos;
int main(void){

    int n,q;
    char c;
    scanf("%d %d",&n,&q);
    // build function tree
    for(int i=0;i<n;i++){
        getchar();
        scanf("%c",&c);
        nfunc = c-'a';
        scanf(" %s",str[nfunc]);
        func[nfunc] = build();
        pos=0;
    }
    // get number ans calculate
    for(int i=0;i<q;i++){
        getchar();
        scanf("%c",&c);
        nfunc = c-'a';
        for(int j=0;j<5;j++)
            scanf("%lld",&num[j]);
        printf("%lld\n",Mod(cal(func[nfunc])));
    }
    return 0;
}
long long Mod(long long num){
    num %= 998244353;
    if(num < 0) num += 998244353;
    return num;
}
long long cal(Node* root){
    char c = root->ch;
    // case for X,A,B,C,D
    if(65<=c&&c<=90){
        if(c=='X') return num[0];
        else return num[c - 64];
    }
    char left = root->left->ch,right = root->right->ch;
    // case for operator
    if(c == '@'){
        long long x = num[0],ans;
        if(65<=right&&right<=90) num[0] = num[right-64];
        else if(right=='+'||right=='-'||right=='*'||right=='@') num[0] = cal(root->right);
        ans = cal(func[left-'a']);
        num[0] = x;
        return ans;
    }
    else if(c=='+') return cal(root->left) + cal(root->right);
    else if(c=='-') return cal(root->left) - cal(root->right);
    else if(c=='*') return cal(root->left) * cal(root->right);
}
Node* build(){
    char c  = str[nfunc][pos++];
    if(c!='+'&&c!='-'&&c!='*'&&c!='@') return create(c);
    else {
        Node* root = create(c);
        root->left = build();
        root->right = build();
        return root;
    }
}
Node* create(char c){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->ch = c;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
void traverse(Node* root){
    if(root!=NULL){
        printf("%c",root->ch);
        traverse(root->left);
        traverse(root->right);
    }
}