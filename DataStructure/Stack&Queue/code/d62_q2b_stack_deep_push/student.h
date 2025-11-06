#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  int a[pos];
  for(int i=pos-1;i>=0;i--){
    a[i] = this->top();
    this->pop();
  }
  this->push(value);
  for(int i=0;i<pos;i++){
    this->push(a[i]);
  }
}

#endif
