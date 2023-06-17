#include<iostream>
#include<stack>
#include<string>
#include<map>
using namespace std;
map<char,char> m = {
    {'(',')'},
    {'[',']'},
    {'{','}'},
    {'<','>'}
};
int main(){
    int n;
    cin >> n;
    getchar(); //get '\n'
    for(int j=1;j<=n;j++){
        string str;
        stack<char> s;
        int len;
        bool valid = true;

        getline(cin,str);
        len = str.length();
        for(int i=0;i<len;i++){
            if(str[i]=='('||str[i]=='['||str[i]=='{'||str[i]=='<') s.push(str[i]); //when meet left component then push
            else if(str[i]==' ') continue; //when meet space then jump
            else{ //when meet right component then pop and check
                if(s.empty() || (str[i]!=m[s.top()])){ //find map
                    valid = false;
                    s.pop();
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty()){
            valid = false;
            //cout << "not empty\n";
        }
        if(valid) cout << "Case " << j << ": Yes\n";
        else cout << "Case " << j << ": No\n";
    }
    return 0;
}