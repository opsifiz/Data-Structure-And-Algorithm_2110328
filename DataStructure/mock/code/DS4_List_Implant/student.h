#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "list.h"
template <typename T>
void CP::list<T>::implant(CP::list<T> &other,int pos1,int pos2,int count){
    // Edit here.
    if(count == 0) return;

    node *p = this->mHeader->next;
    while(pos1--){
        p = p->next;
    }

    node *q = other.mHeader->next;
    while(pos2--){
        q = q->next;
    }

    this->mSize += count;
    other.mSize -= count;
    
    node *r = q;
    while(--count){
        r = r->next;
    }

    node *before = q->prev;
    node *after = r->next;

    before->next = after;
    after->prev = before;

    p->next->prev = r;
    r->next = p->next;
    p->next = q;
    q->prev = p;

}
#endif