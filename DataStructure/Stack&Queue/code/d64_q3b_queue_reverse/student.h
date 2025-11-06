#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  int len = b-a+1;
  while(len>1){
    int l = (mFront+a)%mCap, r = (mFront+b)%mCap;
    std::swap(mData[l],mData[r]);
    len -= 2;
    a++, b--;
  }
}

#endif
