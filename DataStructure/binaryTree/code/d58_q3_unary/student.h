#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* ptr) const {
  //you may write additional code here
  if(ptr == NULL) return 0;
  if(ptr->left == NULL && ptr->right == NULL) return 0;
  size_t valid = (ptr->left!=NULL&&ptr->right==NULL)||(ptr->left==NULL&&ptr->right!=NULL);
  valid += process(ptr->left)+process(ptr->right);
  return valid;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
size_t CP::map_bst<KeyT,MappedT,CompareT>::count_unary() const {
  //write your code here
  return process(mRoot);
}

#endif
