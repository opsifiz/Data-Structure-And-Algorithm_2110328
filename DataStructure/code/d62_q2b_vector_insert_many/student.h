#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<set>
#include<algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  int n = this->size(), m = data.size();
  std::set<int> used;
  vector<T> newV = vector<T>(n+m);
  sort(data.begin(), data.end());
  for(int i=0;i<m;i++){
    auto x = data[i];
    newV[x.first+i] = x.second;
    used.insert(x.first+i);
  }
  // for(int i=0;i<n+m;i++) std::cout<<newV[i]<<' '; std::cout<<'\n';
  int ind = 0, i=0;
  while(ind<n+m){
    if(used.find(ind) == used.end()){
      newV[ind] = *(this->begin()+i);
      i++;
    }
    ind++;
  }
  *(this) = newV;
}

#endif
