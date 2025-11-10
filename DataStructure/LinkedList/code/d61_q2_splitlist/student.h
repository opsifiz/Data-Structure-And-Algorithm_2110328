void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int sz = this->mSize;
    if(sz == 0) return;
    int a = sz/2+(sz%2);
    int b = sz-a;
    node *f = mHeader->next;
    node *p = mHeader->next;
    for(int i=1;i<a;i++){
        p = p->next;
    }
    
    node *q = p->next;
    node *l = mHeader->prev;

    p->next = NULL;
    q->prev = NULL;

    if(a > 0){
        list1.mHeader->prev->next = f;
        f->prev = list1.mHeader->prev;

        list1.mHeader->prev = p;
        p->next = list1.mHeader;

        list1.mSize += a;
    }
    
    if(b > 0){
        list2.mHeader->prev->next = q;
        q->prev = list2.mHeader->prev;

        list2.mHeader->prev = l;
        l->next = list2.mHeader;
        
        list2.mSize += b;
    }

    mHeader->next = mHeader->prev = mHeader;
    mSize = 0;
}
