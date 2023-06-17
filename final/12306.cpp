#include<queue>
#include<iostream>
using namespace std;
int status[16][301][401]={0}; //L,HP,MHP
struct Node{
    int lv,Hp,m_Hp;
    int step;
    Node(int lv,int Hp,int m_Hp,int step):lv(lv),Hp(Hp),m_Hp(m_Hp),step(step){};
};
int main(){
    queue<Node> q;
    int attack[16],heal[16]; //for level data
    int L,HP,MHP,MDMG;

    cin >> L >> HP >> MHP >> MDMG;
    for(int i=1;i<=L;i++)
        cin >> attack[i] >> heal[i];
    q.push(Node(1,HP,MHP,0));
    status[L][HP][MHP] = 1; //record status

    while(!q.empty()){
        Node n = q.front();
        if(n.m_Hp<=0) break; // monster died
        q.pop(); // after break in order to keep n in queue
        int nhp = n.Hp-MDMG; // every round monster attack
        if(n.Hp>0){ // means alive
            // level up
            if(n.lv+1<=L && status[n.lv+1][nhp][n.m_Hp]!=1){
                q.push(Node(n.lv+1,nhp,n.m_Hp,n.step+1));
                status[n.lv+1][nhp][n.m_Hp] = 1;
            }
            // attack
            int mhp = max(n.m_Hp-attack[n.lv],0);
            if(status[n.lv][nhp][mhp]!=1){
                q.push(Node(n.lv,nhp,mhp,n.step+1));
                status[n.lv][nhp][mhp] = 1;
            }
        }
        // heal
        nhp = min(n.Hp+heal[n.lv],HP)-MDMG; // maximum is HP
        if(n.Hp>0 && status[n.lv][nhp][n.m_Hp]!=1){
            q.push(Node(n.lv,nhp,n.m_Hp,n.step+1));
            status[n.lv][nhp][n.m_Hp] = 1;
        }
    }
    if(q.empty()) cout << "-1\n";
    else cout << q.front().step << endl;
    return 0;
}