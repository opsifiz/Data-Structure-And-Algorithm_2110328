
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {
    /*

        “In war, then, let your great object be victory, not lengthy campaigns.”
        ― Sun Tzu, The Art of War 

    */
   /*
        Orz Orz Orz ajarn nattee115 TT >:( โจทย์ยากมาก
   */
    node *p = mHeader->next->next;
    node *q = ls.mHeader->next;

    int n = mSize, m = ls.mSize;

    mSize += ls.mSize;
    ls.mSize = 0;

    while(q != ls.mHeader){
        node *nextP = p->next;
        node *nextQ = q->next;
        
        q->prev = p->prev;
        p->prev->next = q;
        q->next = p;
        p->prev = q;

        p = p==mHeader?p:nextP;
        q = nextQ;
    }

    ls.mHeader->next = ls.mHeader->prev = ls.mHeader;
}

#endif
