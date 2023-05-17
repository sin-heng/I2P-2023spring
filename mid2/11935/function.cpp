#include "function.h"
void _stack::push(const _node N){
    _node* n = new _node(N.data);
    End->next = n;
    End->next->prev = End;
    End = End->next;
}
void _stack::pop(){
    if(!this->Empty()){
        End = End->prev;
        delete End->next;
        End->next = NULL;
    }
}
_node* _stack::get_data(){
    if(!this->Empty()) return End;
    else return NULL;
}
void _queue::push(const _node N){
    _node* n = new _node(N.data);
    End->prev->next = n;
    n->prev = End->prev;
    End->prev = n;
    n->next = End;
}
void _queue::pop(){
    if(!this->Empty()){
        Begin = Begin->next;
        delete Begin->prev;
        Begin->prev = NULL;
    }
}
_node* _queue::get_data(){
    if(!this->Empty()) return Begin->next;
    else return NULL;
}