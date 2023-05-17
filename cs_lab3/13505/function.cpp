#include "function.h"
#include<string>
#include<ctype.h>
#include<iostream>
using namespace std;
String_Calculator::String_Calculator(const string a){this->s = a;}
String_Calculator& String_Calculator::Add(const string b){
    this->s += b;
    return *this;
}
String_Calculator& String_Calculator::Subtract(const string b){
    int index = this->s.find(b);
    if(index==-1) this->s = "error";
    else{
        string s1 = this->s.substr(0,index), s2 = this->s.substr(index+b.length(),this->s.length()-index-b.length());
        this->s = s1 + s2;
    }
    return *this;
}
String_Calculator& String_Calculator::Shift(const string b){
    bool flag = false;
    for(int i=0;i<b.length();i++)
        if(!isdigit(b[i])){
            flag = true;
            break;
        }
    if(flag){
        this->s = "error";
        return *this;
    }
    int k = stoi(b),Index;
    char table[36];
    for(int i=0;i<10;i++) table[i] = '0'+i;
    for(int i=10;i<36;i++) table[i] = 'a'-10 +i;
    for(int i=0;i<this->s.length();i++){
        if(this->s[i]>='a') Index = this->s[i]-'a'+10;
        else Index = this->s[i]-'0';
        Index += k;
        Index %= 36;
        this->s[i] = table[Index];
    }
    return *this;
}
void String_Calculator::output() const{
    cout << this->s << endl;
}