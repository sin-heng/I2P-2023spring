#include "function.h"
Darray::~Darray(){
    delete [] this->data;
}
int& Darray::operator[](int x){
    return this->data[x];
}
void Darray::pushback(int x){
    // if full then double size, and copy data
    if(this->capacity == this->size){
        // double size and create new array
        this->capacity *= 2;
        int* tmp = new int[this->capacity];
        // copy data
        for(int i=0;i<this->size;i++) tmp[i] = this->data[i];
        // delete old array
        delete [] this->data;
        this->data = tmp;
    }
    this->size += 1;
    this->data[this->size-1] = x;
}
void Darray::clear(void){
    this->size = 0;
}
int Darray::length(void){
    return this->size;
}