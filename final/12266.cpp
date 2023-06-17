#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
Wa	Waninoko
Mi	Milotic
Ma	Magikarp
Va	Vaporeon
Sh	Sharpedo
Tapu	Tapu Fini
Em	Empoleon
La	Lapras
Pi, Pe	Pikachu
Me	Mega Gyarados
*/
map<string,string> createMap(){
    map<string,string> m;
    m.insert(pair<string,string>("Wa","Waninoko"));
    m.insert(pair<string,string>("Mi","Milotic"));
    m.insert(pair<string,string>("Ma","Magikarp"));
    m.insert(pair<string,string>("Va","Vaporeon"));
    m.insert(pair<string,string>("Sh","Sharpedo"));
    m.insert(pair<string,string>("Tapu","Tapu Fini"));
    m.insert(pair<string,string>("Em","Empoleon"));
    m.insert(pair<string,string>("La","Lapras"));
    m.insert(pair<string,string>("Pi","Pikachu"));
    m.insert(pair<string,string>("Pe","Pikachu"));
    m.insert(pair<string,string>("Me","Mega Gyarados"));
    return m;
}
int main(){
    map<string,string> m = createMap();
    int n;
    string name,school,tmp;
    cin >> n;
    while(n--){
        cin >> name >> school;
        if(name[0]=='T') tmp = name.substr(0,4); //for Tapu
        else tmp = name.substr(0,2);
        auto i = m.find(tmp);
        if(i==m.cend()) cout << name << " is looking for a Chinese tutor, too!" << endl;
        else cout << name << " the " << school << " " << i->second << endl;
    }
    return 0;
}