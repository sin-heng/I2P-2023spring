#include<iostream>
#include<queue>
#include<string>
using namespace std;
typedef pair<int,int> pii;
int visit[1005][1005] = {0};
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
char Map[1005][1005];
struct node{
    node (pii tmp,int p):p(tmp),path(p){};
    pii p;
    int path;
};
int main(){
    queue <node> Q;
    pii start,end;
    string stmp;
    int N,M;
    cin >> N >> M;
    // read map and get start, end
    for(int i=1;i<=N;i++){
        cin >> stmp;
        stmp = '#' + stmp + '#';
        for(int j=0;j<=M+1;j++){
            if(stmp[j]=='P') start=pii(i,j);
            else if(stmp[j]=='@') end=pii(i,j);
            else if(stmp[j]=='#') visit[i][j] = 1;
        }
    }
    for(int j=0;j<=M+1;j++) visit[0][j] = visit[N+1][j] = 1;
    Q.emplace(start,0);
    while(Q.size()){
        node n = Q.front();Q.pop();
        if(n.p==end){
            cout << n.path << endl;
            return 0;
        }
        for(int i=0;i<4;i++){
            int idx=n.p.first+di[i],idy=n.p.second+dj[i];
            if(visit[idx][idy]==1) continue;
            Q.emplace(pii(idx,idy),n.path+1);
            visit[idx][idy]=1;
        }
    }
    cout << "-1\n";
    return 0;
}