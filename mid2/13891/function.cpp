// date: 2023/5/4
// status: all accepted
#include "function.h"
void CamelCase::convert(){
    converted = true;
    name[0] = toupper(name[0]);
    for(int i = 0; i < name.length(); i++){
        if(name[i] == '-'){
            name[i+1] = toupper(name[i+1]);
            name = name.substr(0,i) + name.substr(i+1,name.length()-(i+1));
        }
    }
}
void CamelCase::revert(){
    converted = false;
    name[0] = tolower(name[0]);
    for(int i = 1; i < name.length(); i++){
        if(isupper(name[i])){
            name[i] = tolower(name[i]);
            name = name.substr(0,i) + "-" + name.substr(i,name.length()-(i));
        }
    }
}