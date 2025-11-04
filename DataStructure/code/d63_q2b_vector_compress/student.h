#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    this->mCap = this->mSize;
    T *v = this->mData;
    this->mData = new T[this->mCap];
    for(int i=0;i<this->mSize;i++){
        this->mData[i] = *(v+i);
    }
    delete [] v;
}

#endif
