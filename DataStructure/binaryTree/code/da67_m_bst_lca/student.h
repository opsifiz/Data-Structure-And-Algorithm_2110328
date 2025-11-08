
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"
#include<vector>


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // You may need this function

    const KeyT &pk = (*p).first;
    const KeyT &qk = (*q).first;
    const KeyT &nk = n->data.first;

    if(mLess(pk,nk) && mLess(qk,nk)) return recursive(n->left, p, q);
    if(mLess(nk,pk) && mLess(nk,qk)) return recursive(n->right, p, q);

    return n;
}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    // Write your code here
    return recursive(this->mRoot, p, q);
    
}

#endif
