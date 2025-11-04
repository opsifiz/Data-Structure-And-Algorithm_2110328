#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  int n = pos.size();
  for(int i=n-1;i>=0;i--){
    int p = pos[i];
    this->erase(this->begin()+p);
  }
}

#endif
