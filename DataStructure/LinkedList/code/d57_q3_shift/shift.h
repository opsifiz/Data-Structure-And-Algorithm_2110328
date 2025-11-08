void shift(int k) {
	// TODO: Add your code here
	while(k < 0) k += this->mSize;
	k %= this->mSize;
	if(k == 0) return;

	while(k--){
		T temp = mHeader->next->data;
		mHeader = mHeader->next;
		mHeader->prev->data = temp;
	}
}
