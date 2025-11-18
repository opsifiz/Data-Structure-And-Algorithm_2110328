#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "map_bst.h"

//this is the modify() function to be submitted
template <typename KeyT,
          typename MappedT,
          typename CompareT >
void CP::map_bst<KeyT,MappedT,CompareT>::modify(
	CP::map_bst<KeyT,MappedT,CompareT> &other
) {
	
	//your code here
	node *cur = this->mRoot;
	node *parent = NULL;

	if(other.mRoot == NULL) return;

	while(cur != NULL && cur->data != other.mRoot->data){
		if(compare(cur->data.first,other.mRoot->data.first) == -1){
			parent = cur;
			cur = cur->right;	
		}else{
			parent = cur;
			cur = cur->left;
		}
	}

	if(cur == NULL){
		mSize += other.mSize;
		if(compare(other.mRoot->data.first,parent->data.first) == -1){
			parent->left = other.mRoot;
		}else{
			parent->right = other.mRoot;
		}
	}else{
		if(cur->left == NULL && cur->right == NULL){
			mSize += other.mSize-1;
			cur->left = other.mRoot->left;
			cur->right = other.mRoot->right;
			other.mRoot->parent = parent;
		}
	}


	other.mRoot = NULL;
	other.mSize = 0;

	return;
}

//you may use this function to traverse and graft
template <typename KeyT,
          typename MappedT,
          typename CompareT >
void CP::map_bst<KeyT,MappedT,CompareT>::graft(
	CP::map_bst<KeyT,MappedT,CompareT>::node* n, CP::map_bst<KeyT,MappedT,CompareT>::node* m, size_t otherSize
) {
	
	//your code here
	
	return;
}

#endif
