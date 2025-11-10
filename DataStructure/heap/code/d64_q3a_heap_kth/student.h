#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> temp(mData,mData+std::min((int)8,(int)mSize));
  std::sort(temp.begin(),temp.end(),mLess);
  return temp[temp.size()-k];
}

#endif
