#include "function.h"
// constructor
Food::Food(){
    fly = 0;
    pos = FLOOR;
}
Food::Food(string& str){
    name = str;
    fly = 0;
    pos = FLOOR;
}
// copy constructor
Food::Food(const Food& f){
    name = f.name;
    fly = f.fly;
    pos = f.pos;
}
// functions
// eaten: the food is eaten, change its position
// thrown: the food is thrown, change its position
// on_floor: return whether the food is on the floor
// get_name: return the Food's name
// get_fly: return the amount of the fly
void Food::eaten(){
    pos = STOMACH;
}
void Food::thrown(){
    pos = TRASHCAN;
}
bool Food::on_floor(){
    if(pos==FLOOR) return true;
    else return false;
}
string Food::get_name(){
    return name;
}
int Food::get_fly(){
    return fly;
}
// operators
// < : use this operator to sort the food so the output of on-floor food satisfy the requirement
// == : determine whether the food's name is same as a string
// << : output the food as the mentioned output format
bool Food::operator < (const Food& f){
    if(pos==FLOOR){
        if(f.pos==FLOOR) return name<f.name;
        else return true;
    }
    else{
        if(f.pos==FLOOR) return false;
        else return name<f.name;
    }
}
bool Food::operator == (const string& str){
    if(name.compare(str)==0) return true;
    else return false;
}
ostream& operator << (ostream& cout, Food f){
    cout << f.name;
    return cout;
}

Fruit::Fruit(){}
Fruit::Fruit(string& str){
    name = str;
}
// five_min_pass: 5 min passes
// sickness: return whether the fruit makes someone sick
// += : mix the food together
void Fruit::five_min_pass(){
    if(pos==FLOOR) fly += 4;
}
bool Fruit::sickness(){
    if(fly>=10 && pos==STOMACH){
        fly=0;
        return true;
    }
    else return false;
}
void Fruit::operator += (Fruit& f){
    name = f.name + name;
    fly += f.fly;
}
void Fruit::operator += (Meat& m){
    name = m.get_name() + name;
    fly += m.get_fly();
}

Meat::Meat(){}
Meat::Meat(string& str){
    name = str;
}
// five_min_pass: 5 min passes
// sickness: return whether the meat makes someone sick
// += : mix the food together
void Meat::five_min_pass(){
    if(pos==FLOOR) fly += 5;
}
bool Meat::sickness(){
    if(fly>=20 && pos==STOMACH){
        fly=0;
        return true;
    }
    else return false;
}
void Meat::operator += (Fruit& f){
    name = f.get_name() + name;
    fly += f.get_fly();
}
void Meat::operator += (Meat& m){
    name = m.get_name() + name;
    fly += m.get_fly();
}