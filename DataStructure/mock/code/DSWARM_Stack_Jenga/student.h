#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::jenga(char c, int a)
{
    // Your code here
    if(c == 'c') mSize = mSize-a;
    else{
        a = mSize-a;
        for(int i=a;i<mSize;i++) std::swap(mData[i-1],mData[i]);
    }
}

#endif