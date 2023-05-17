// 13485 - String Calculator(class) 
// all accepted
#include<iostream>
#include<string>
#include "function.h"
#include<algorithm>
using namespace std;
String_Calculator::String_Calculator(const string a){this->s = a;}
String_Calculator& String_Calculator::Add(const string b){
    this->s += b;
    return *this;
}
String_Calculator& String_Calculator::Subtract(const string b){
    int found = this->s.find(b);
    if(found!=-1){
        string s1 = this->s.substr(0,found),s2 = this->s.substr(found+b.length(),this->s.length()-b.length());
        this->s = s1 + s2;
    }
    else this->s = "error";
    return *this;
}
String_Calculator& String_Calculator::DividedBy(const string b){
    int found = this->s.find(b),times=0;
    while(found!=-1){
        this->s= this->s.substr(found+1,this->s.length()-(found+1));
        times++;
        found = this->s.find(b);
    }
    this->s = char(times%10+48);
    times/=10;
    while(times!=0){
        this->s += char(times%10+48);
        times/=10;
    }
    reverse(this->s.begin(),this->s.end());
    return *this;
}
void String_Calculator::output() const{
    cout << this->s << endl;
}