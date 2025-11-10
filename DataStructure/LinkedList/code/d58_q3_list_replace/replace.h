void replace(const T& x, list<T>& y) {
  //write your code here
  node *it = mHeader->next;

  while(it != mHeader){
    node *prv = it->prev;
    node *nxt = it->next;
    if(it->data == x){
      it->next->prev = it->prev;
      it->prev->next = it->next;
      mSize--;

      for(auto temp=y.begin();temp!=y.end();temp++){
        node *n = new node(*temp,prv,NULL);
        prv->next = n;
        prv = prv->next;
        mSize++;
      }
      prv->next = nxt;
      nxt->prev = prv;

      it = nxt;
    }else{
      it = it->next;
    }
  }
}
