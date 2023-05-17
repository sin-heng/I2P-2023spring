// 13862 - Pineapple senpai’s family 
#include "function.h"
int MATE=0;
void Person::describe(string* arr, int now, int len){
    // use getRelative to get narrator
    Person* tmp = this->getRelative(arr,now,len-2);
    // set attribute
    if(arr[len-2].compare("Gender")==0){
        if(arr[len-1].compare("FEMALE")==0) tmp->gender = FEMALE;
        else tmp->gender = MALE;
    }
    else if(arr[len-2].compare("Age")==0){tmp->age = stoi(arr[len-1]);}
    else if(arr[len-2].compare("Name")==0){tmp->name = arr[len-1];}
    else if(arr[len-2].compare("Personality")==0){
        if(tmp->personality.length()==0) tmp->personality = arr[len-1];
        else tmp->personality = tmp->personality + " " + arr[len-1];
    }
}
Person* Person::getRelative (string* arr, int now, int len){
    if(now == len) return this; // reach the terminal condition, return calling object
    Person* tmp = NULL;
    if(arr[now].compare("ParentA")==0){
        // structure
        // 1. has parentA
        // 2. has no parentA, has parentB, and parentB has mate
        // 3. has no parentA, has parentB, and parentB doesn't have mate
        // 4. has no parentA, and has no parentB
        if(this->parentA!=NULL) tmp = this->parentA; // case 1
        else{
            if(this->parentB!=NULL){
                // case 2
                if(this->parentB->mate!=NULL){
                    tmp = this->parentB->mate;
                    this->parentA = tmp;
                    tmp->child = this;
                } 
                else // case 3
                {
                    tmp = new Person;
                    this->parentA = tmp;
                    tmp->child = this;
                    
                    this->parentB->mate = tmp;
                    tmp->mate = this->parentB;
                    MATE++;
                }
            }
            else // case4
            {
                tmp = new Person;
                this->parentA = tmp;
                tmp->child = this;
            }
        } 
    } 
    else if(arr[now].compare("ParentB")==0){
        // structure
        // 1. has parentB
        // 2. has no parentB, has parentA, and parentA has mate
        // 3. has no parentB, has parentA, and parentA doesn't have mate
        // 4. has no parentB, and has no parentA
        if(this->parentB!=NULL) tmp = this->parentB; // case 1
        else{
            if(this->parentA!=NULL){
                // case 2
                if(this->parentA->mate!=NULL){
                    tmp = this->parentA->mate;
                    this->parentB = tmp;
                    tmp->child = this;
                } 
                else // case 3
                {
                    tmp = new Person;
                    this->parentB = tmp;
                    tmp->child = this;
                    
                    this->parentA->mate = tmp;
                    tmp->mate = this->parentA;
                    MATE++;
                }
            }
            else // case4
            {
                tmp = new Person;
                this->parentB = tmp;
                tmp->child = this;
            }
        } 
    } 
    else if(arr[now].compare("Mate")==0){
        // structure
        // 1. has mate
        // 2. has no mate, has child, and child has two parents
        // 3. has no mate, has child, and child doesn't have two parents
        // 4. has no mate, and has no child
        if(this->mate!=NULL) tmp = this->mate; // case 1
        else{
            if(this->child!=NULL){
                // case 2
                if(this->child->parentA!=NULL && this->child->parentB!=NULL){
                    // avoid collide
                    if(this->child->parentA==this) tmp = this->child->parentB;
                    else tmp = this->child->parentA;
                    this->mate = tmp;
                    tmp->mate = this;
                    MATE++;
                } 
                else // case 3
                {
                    tmp = new Person;
                    this->mate = tmp;
                    tmp->mate = this;
                    
                    tmp->child = this->child;
                    // avoid collide
                    if(this->child->parentA==this) this->child->parentB = tmp;
                    else this->child->parentA = this;
                    MATE++;
                }
            }
            else // case4
            {
                tmp = new Person;
                this->mate = tmp;
                tmp->mate = this;
                MATE++;
            }
        } 
    }
    else if(arr[now].compare("Child")==0){
        // structure
        // 1. has child
        // 2. has no child, has mate, and mate has child
        // 3. has no child, has mate, and mate doesn't have child
        // 4. has no child, and has no mate
        if(this->child!=NULL) tmp = this->child; // case 1
        else{
            if(this->mate!=NULL){
                // case 2
                if(this->mate->child!=NULL){
                    tmp = this->mate->child;
                    this->child = tmp;
                    // avoid collide
                    if(tmp->parentA==this->mate) tmp->parentB = this;
                    else tmp->parentA = this;
                } 
                else // case 3
                {
                    tmp = new Person;
                    this->child = tmp;
                    tmp->parentA = this;
                    this->mate->child = tmp;
                    tmp->parentB = this->mate;
                }
            }
            else // case4
            {
                tmp = new Person;
                this->child = tmp;
                tmp->parentA = this;
            }
        }
    }
    return tmp->getRelative(arr,now+1,len);
}
int getAns(){
    return MATE;
}