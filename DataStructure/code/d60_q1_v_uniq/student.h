#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include<set>
#include<vector>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  std::set<T> s;
  std::vector<int> pos;
  CP::vector<T> newV;

  int idx = 0;
  auto st = this->begin();
  while(st+idx != this->end()){
    if(s.find(*(this->begin()+idx)) == s.end()){
      s.insert(*(this->begin()+idx));
      newV.push_back(*(this->begin()+idx));
    }else{
      pos.push_back(idx);
    }
    idx++;
  }
  *this = newV;
  // int n = pos.size();
  // for(int i=n-1;i>=0;i--){
  //   int p = pos[i];
  //   this->erase(this->begin()+p);
  // }
}

#endif
