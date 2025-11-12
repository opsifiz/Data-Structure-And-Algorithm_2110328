#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::block_insert(size_t p, size_t m, const T &element)
{
	// write your code here
	CP::queue<T> temp;
	int cnt = 0;
	int oldSize = mSize;
	ensureCapacity(mSize+m);
	mSize += m;
	if(p < oldSize/2){
		mFront = (mFront-m+mCap)%mCap;

		for(int i=0;i<p;i++){
			int from = (mFront+m+i)%mCap;
			int to = (mFront+i)%mCap;
			mData[to] = mData[from];
		}
	}else{
		for(int i=0;i<oldSize-p;i++){
			int from = (mFront+oldSize-i-1)%mCap;
			int to = (mFront+mSize-i-1)%mCap;
			mData[to] = mData[from];
		}
	}
	for(int i=0;i<m;i++){
		int idx = (mFront+p+i)%mCap;
		mData[idx] = element;
	}
	// for(int i=0;i<mSize;i++) std::cout<<mData[(mFront+i+mSize)%mCap]<<' '; std::cout<<'\n';
}

#endif
