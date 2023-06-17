#include <iostream>
#include <set>
#include <map>
#define N int(2e5)
using namespace std;
struct Guest{
    int id,arrival,group,duration;
};
// lambda
auto arrival = [](const Guest a,const Guest b){return a.arrival<b.arrival;};
auto group_arr = [](const Guest a,const Guest b){return a.group==b.group?a.arrival>b.arrival:a.group<b.group;};
// data structure
set<Guest,decltype(arrival)> waiting_arr(arrival);
set<Guest,decltype(group_arr)> waiting_group(group_arr);
map<int,int> table_avl; // <size,number>
multiset<pair<int,int>> table_use; // <release time,size>
// variable
int ans[N];
Guest guest[N];
// function
bool assign_table(int time){
    // no table or no guest waiting
    if(table_avl.empty() || waiting_arr.empty()) return false;
    Guest guest = *(waiting_arr.begin());
    auto table = table_avl.lower_bound(guest.group);
    // didn't find table
    if(table==table_avl.end()){
        int largest_size = table_avl.rbegin()->first;
        auto it = waiting_group.upper_bound(Guest{0,0,largest_size,0});
        // didn't find
        if(it == waiting_group.begin()) return false;
        guest = *(--it);
        table = table_avl.lower_bound(guest.group);
    }
    int table_size = table->first;
    // guest
    ans[guest.id] = time;
    waiting_arr.erase(guest);
    waiting_group.erase(guest);
    // table avl
    table_avl[table_size]--;
    if(!table_avl[table_size]) table_avl.erase(table);
    // table use
    table_use.insert({time+guest.duration,table_size});
    return true;
}
// prepare table
void prepare(int time){
    // table_use isn't empty and the nearest release one can release
    while(!table_use.empty() && (*table_use.begin()).first<=time){
        int release_time = (*table_use.begin()).first;
        // release table
        table_avl[(*table_use.begin()).second]++;
        table_use.erase(table_use.begin());
        // same time release
        if(table_use.size() && table_use.begin()->first==release_time) continue;
        // after release all table then assign 
        while(assign_table(release_time));
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> guest[i].arrival >> guest[i].group >> guest[i].duration;
        guest[i].id = i;
    }
    int x,y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        table_avl[x] = y;
    }
    for(int i=0;i<n;i++){
         // prepare before guest arrive
        prepare(guest[i].arrival-1);
        // insert guest into list
        waiting_arr.insert(guest[i]);
        waiting_group.insert(guest[i]);
        // assign table
        prepare(guest[i].arrival);
        assign_table(guest[i].arrival);
    }
    // if some guests still using 
    if(!table_use.empty()) prepare(1e9);
    for(int i=0;i<n;i++) cout << ans[i] << endl;
    return 0;
}