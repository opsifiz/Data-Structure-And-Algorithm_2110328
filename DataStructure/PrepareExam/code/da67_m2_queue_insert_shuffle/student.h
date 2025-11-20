#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	// write your code here
	int n = mSize;
	int m = items.size();
	ensureCapacity(n+m);
	CP::queue<T> temp;
	for(int i=0;i<pos;i++){
		temp.push(mData[(mFront+i)%mCap]);
	}

	int i = pos, j = 0;
	
	while(i<n && j<m){
		temp.push(items[j]);
		temp.push(mData[(mFront+i)%mCap]);
		i++;
		j++;
	}
	
	while(i<n){
		temp.push(mData[(mFront+i)%mCap]);
		i++;
	}
	
	while(j<m){
		temp.push(items[j]);
		j++;
	}

	mSize = n+m;
	*this = temp;
}

#endif
