#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if(n == NULL) return 0;
  int lhs = n->left==NULL?0:process(n->left);
  int rhs = n->right==NULL?0:process(n->right);
  return 1+lhs+rhs;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  int a = 0, b = 0;
  if(this->mRoot == NULL) return std::pair<KeyT,MappedT>();
  if(this->mRoot->left != NULL){
    a = process(this->mRoot->left);
    left.mRoot = this->mRoot->left;
    this->mRoot->left = NULL;
    left.mSize = a;
    this->mSize -= a;
  }
  if(this->mRoot->right!= NULL){
    b = process(this->mRoot->right);
    right.mRoot = this->mRoot->right;
    this->mRoot->right = NULL;
    right.mSize = b;
    this->mSize -= b;
  }
  return this->mRoot->data;
}

#endif

