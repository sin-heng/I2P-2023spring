// date: 2023/5/4
// status: 
#include "function.h"
// [TODO] Implement this function
// Test if any player is at this position.
bool Field::SomeoneIsHere(int x, int y){
    for(int i=0;i<p;i++)
        if(player[i]->IsHere(x,y)) return true;
    return false;
}

// [TODO] Implement this function
// Find the player who is holding the ball now.
int Field::GetWho(){
    for(int i=0;i<p;i++)
        if(player[i]->IsHoldingBall()) return i;
    return -1;
}

// [TODO] Implement this function
void Field::handleBallKicked(int dx, int dy){
    ball->SetX(ball->GetX()+dx);
    ball->SetY(ball->GetY()+dy);
    while(0<=ball->GetX() && ball->GetX()<n && 0<=ball->GetY() && ball->GetY()<m){
        for(int i=0;i<p;i++){
            if(player[i]->IsHere(ball->GetX(),ball->GetY())){
                return;
            }
        }
        ball->SetX(ball->GetX()+dx);
        ball->SetY(ball->GetY()+dy);
    }
    if(ball->GetX()<0) ball->SetX(0);
    else if(ball->GetX()>=n) ball->SetX(n-1);
    if(ball->GetY()<0) ball->SetY(0);
    else if(ball->GetY()>=m) ball->SetY(m-1);
}
