#include "function.h"
// 123*456 = 456*(100 + 10 + 10 + 1 + 1 + 1)
INT INT::operator*(INT I){
    INT total;
    for(int i=0;i<I.len;i++){
        for(int j=0;j<I.data[i];j++)  
            total = total + *this;
        this->mulby10();
    }
    *this = total;
    return *this;
}