#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  if(pos >= this->mSize) return;
  int idx = (this->mFront+pos)%this->mCap;
  T temp = this->mData[idx];
  
  for(int i=pos;i<this->mSize-1;i++){
    this->mData[(this->mFront+i)%this->mCap] = this->mData[(this->mFront+i+1)%this->mCap];
  }
  this->mData[(this->mFront+this->mSize-1)%this->mCap] = temp;
}

#endif
