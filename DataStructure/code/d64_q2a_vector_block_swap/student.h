#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  int ia = a-this->begin();
  int ib = b-this->begin();

  if(ia > ib){
    std::swap(ia,ib);
    std::swap(a,b);
  }

  if(!(0<=ia&&ia<=this->mSize)||!(0<=ib&&ib<=this->mSize)) return 0;

  if(ia+m-1 >= ib) return 0;
  if(ib+m-1 >= this->mSize) return 0;
  if(m == 0) return 0;
  while(m--){
    std::swap(*(this->begin()+ia++), *(this->begin()+ib++));
  }
  return 1;
}

#endif
