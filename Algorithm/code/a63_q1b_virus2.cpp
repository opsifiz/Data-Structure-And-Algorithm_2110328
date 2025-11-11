#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

int k;
int a[1<<16], qs[1<<16];

bool valid(int st, int ed){
    if(st+1 == ed || st == ed) return 1;
    int mid = (st+ed)/2;
    return (abs((qs[ed]-qs[mid])-(qs[mid]-qs[st-1]))<=1) && valid(st,mid) && valid(mid+1,ed);
}

void mains(){
    for(int i=1;i<=(1<<k);i++){
        cin>>a[i];
        qs[i] = qs[i-1]+a[i];
    }
    int n = 1<<k;
    cout<<(valid(1,n)?"yes\n":"no\n");
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc>>k;
    while(tc--){
        mains();
    }
} 