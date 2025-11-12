// Your code here

int getHeight(node *n, int &mxImb, KeyT &bestKey, bool &hasVal){
    if(n == NULL) return -1;

    int lh = getHeight(n->left,mxImb,bestKey,hasVal);
    int rh = getHeight(n->right,mxImb,bestKey,hasVal);

    int curImb = abs(lh-rh);

    if(!hasVal || curImb>mxImb || (mxImb==curImb && n->data.first < bestKey)){
        hasVal = 1;
        mxImb = curImb;
        bestKey = n->data.first;
    }

    return 1+std::max(lh,rh);
}


KeyT getValueOfMostImbalanceNode() {
    // Your code here
    int mxImb =  -1;
    KeyT bestKey;
    bool hasVal = 0;
    getHeight(mRoot,mxImb,bestKey,hasVal);
    return bestKey;
}
