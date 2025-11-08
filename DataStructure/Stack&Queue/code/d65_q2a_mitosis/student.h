#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include<vector>
#include<stack>

template <typename T>
void CP::stack<T>::mitosis(int a, int b){
    
    std::stack<T> temp;

    for(int i=0;i<a;i++){
        temp.push(this->top());
        this->pop();
    }
    for(int i=a;i<=b;i++){
        temp.push(this->top());
        temp.push(this->top());
        this->pop();
    }

    while(!temp.empty()){
        this->push(temp.top());
        temp.pop();
    }
}

#endif