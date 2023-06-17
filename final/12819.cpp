#include <iostream>
#include <queue>
#include <cmath>
#define MAX 80
using namespace std;
const int goalrow[]={-1,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3};
const int goalcol[]={-1,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2};
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
class State{
    public:
    int puzzle[4][4];
    int currentMove; // answer
    int preMove; // to test repeat step
    int ex,ey; // x and y of '0'
    int heuristic;

    State(int puzzle[4][4]);
    State(const State& rhs); // copy cnostructor
    void getHeuristic();
    void update(int i,int newx,int newy);
    // lower F value get higher priority
    bool operator<(const State& rhs) const{return currentMove+heuristic>rhs.currentMove+rhs.heuristic;};
};
int main(){
    priority_queue<State> q;
    int puzzle[4][4];
    int ex,ey;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> puzzle[i][j];
            if(!puzzle[i][j]){ex=i;ey=j;}// if puzzle[i][j]==0
        }
    }
    State s(puzzle);
    s.ex=ex;s.ey=ey;
    q.push(s);

    while(!q.empty()){
        State cur = q.top();
        if(cur.heuristic==0){
            cout << cur.currentMove << endl;
            break;
        }
        q.pop(); // for 'if' after while loop
        if(cur.currentMove+cur.heuristic>MAX) continue; // too much step so ignore 
        // try four dirction
        for(int i=0;i<4;i++){
            int newx = cur.ex + dx[i];
            int newy = cur.ey + dy[i];
            // check range
            if(newx<0||newy<0||newx>3||newy>3) continue;
            // check repeat step
            if(i==(cur.preMove^1)) continue;
            State next = cur;
            next.update(i,newx,newy);
            q.push(next);
        }
    }
    if(q.empty()) cout << "-1\n";
    return 0;
}
State::State(int puzzle[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)    
            this->puzzle[i][j] = puzzle[i][j];
    this->currentMove=0;
    this->preMove=this->ex=this->ey=-1;
    getHeuristic();
}
State::State(const State& rhs){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)    
            this->puzzle[i][j] = rhs.puzzle[i][j];
    this->currentMove=rhs.currentMove;
    this->heuristic=rhs.heuristic;
    this->preMove=rhs.preMove;
    this->ex=rhs.ex;
    this->ey=rhs.ey;
}
void State::getHeuristic(){
    int h=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(puzzle[i][j]){
                // get manhattan number
                int goalx = goalrow[puzzle[i][j]];
                int goaly = goalcol[puzzle[i][j]];
                h += abs(goalx-i) + abs(goaly-j);
                // get linear conflict
                if(i==goalx){
                    for(int k=j;k<4;k++)
                        // puzzle[i][k]!=0 && puzzle[i][k] is a goalrow and is i && puzzle[i][k]'s goal is left of puzzle[i][j]
                        if(puzzle[i][k] && goalrow[puzzle[i][k]]==i && puzzle[i][j]>puzzle[i][k]) h+=2;
                }
                if(j==goaly){
                    for(int k=i;k<4;k++)
                        if(puzzle[k][j] && goalcol[puzzle[k][j]]==j && puzzle[i][j]>puzzle[k][j]) h+=2;
                }
            }
        }
    }
    heuristic=h;
}
void State::update(int i,int newx,int newy){
    this->preMove=i;
    swap(puzzle[ex][ey],puzzle[newx][newy]);
    ex=newx;ey=newy;
    currentMove++;
    getHeuristic();
}