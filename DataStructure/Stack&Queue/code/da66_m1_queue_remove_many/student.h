#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include<algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  sort(pos.begin(),pos.end());
  int sz = mSize;
  CP::queue<T> q;
  int ind = 0;
  for(int i=0;i<sz;i++){
    if(pos[ind] == i) ind++;
    else{
      q.push(mData[(mFront+i)%mCap]);
    }
  }
  *(this) = q;
}

#endif
