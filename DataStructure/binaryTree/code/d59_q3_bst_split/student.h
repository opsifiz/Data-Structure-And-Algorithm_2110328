#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  
  node *cur = mRoot;
  node *newRes = NULL;
  node *pnewRes = NULL;

  node *newTree = NULL;
  node *pnewTree= NULL;

  while(cur != NULL){

    if(val <= cur->data.first){

      node *leftTree = cur->left;
      cur->left = NULL;

      if(newRes == NULL){
        newRes = cur;
        newRes->parent = NULL;
        // newRes->left = NULL;
      }else{
        if(cur->data.first < newRes->data.first){
          newRes->left = cur;
          pnewRes = newRes;
          newRes = newRes->left;
          newRes->parent = pnewRes;
        }else{
          newRes->right = cur;
          pnewRes = newRes;
          newRes = newRes->right;
          newRes->parent = pnewRes;
        }
        // newRes->left = NULL;
      }

      // cur = cur->left;
      cur = leftTree; 

    }else{
      // cur = cur->right;
      node *rightTree= cur->right;
      cur->right = NULL;

      if(newTree == NULL){
        newTree = cur;
        newTree->parent = NULL;
      }else{
        newTree->right = cur;
        pnewTree = newTree;
        newTree = newTree->right;
        newTree->parent = pnewTree;
      }

      cur = rightTree;

    }
  }
  if(newRes != NULL){
    while(newRes->parent != NULL) newRes = newRes->parent;
    result.mRoot = newRes;
  }else{
    result.mRoot = NULL;
  }

  if(newTree != NULL){
    while(newTree->parent != NULL) newTree = newTree->parent;
    mRoot = newTree;
  }else{
    mRoot = NULL;
  }


  return result;
}

#endif
