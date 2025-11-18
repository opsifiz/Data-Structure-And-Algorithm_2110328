#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T> void CP::queue<T>::merge_greater(CP::queue<T> &other) {
  // implement this from scratch
  if(this == &other) return;
  int n = mSize;
  int m = other.mSize;

  CP::queue<T> A = *this, B = other;

  int i = 0, j = 0;
  int Bsz = 0;
  int cnt = 0;

  for(int k=0;k<m;k++){
    if(mData[(mFront+k)%mCap]<other.mData[(other.mFront+k)%other.mCap]){
      cnt++;
    }
  }
  
  ensureCapacity(n+cnt);
  
  i = 0;
  while(i<n+cnt){
    mData[(mFront+i)%mCap] = A.front();
    
    if(!B.empty()){
      
      if(A.front() < B.front()){
        i++;
        mData[(mFront+i)%mCap] = B.front();
      }else{
        other.mData[(other.mFront+Bsz)%other.mCap] = B.front();
        Bsz++;
      }
      
      B.pop();
    }
    
    i++;
    A.pop();
  }
  
  mSize = n+cnt;
  other.mSize = other.mSize-cnt;
  
  // i = 0;
  // while(i<n+cnt){
  //   std::cout<<mData[(mFront+i)%mCap]<<' ';
  //   i++;
  // }
  // std::cout<<'\n';

}

#endif