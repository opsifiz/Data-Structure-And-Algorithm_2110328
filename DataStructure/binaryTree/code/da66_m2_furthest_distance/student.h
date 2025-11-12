#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
	// You MAY use this function
    if(n == NULL) return -1;

	int lh = my_recur(n->left,aux);
    int rh = my_recur(n->right,aux);
    int dis = lh+rh+2;

    if(dis > aux) aux = dis;

    return std::max(lh,rh)+1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
	// write your code here
    if(this->mRoot == NULL) return -1;
    if(this->mRoot->left == NULL && this->mRoot->right == NULL) return 0;
    int ans = 0;
    my_recur(this->mRoot,ans);
    return ans;
}

#endif
