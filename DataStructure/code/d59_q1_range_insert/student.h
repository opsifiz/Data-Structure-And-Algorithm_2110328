#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  int ind = 0;
  int st = position-this->begin();
  while(first != last){
    //DO SOMETING
    this->insert(this->begin()+st+ind, *first);
    first++;
    ind++;
  }
}

#endif
