#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 5e5;

int a[N+5];

void mains(){
    int n, m; cin>>n>>m;
    int k; cin>>k;
    for(int i=1;i<=k;i++){
        int x, y;
        cin>>x>>y;
        a[i] = (x-1)*m+y;
    }
    int nm = n*m;
    sort(a+1,a+k+1);
    int q; cin>>q;
    while(q--){
        int x, y;
        cin>>x>>y;
        int idx = (x-1)*m+y;
        if(idx > a[k]){
            cout<<a[1]+(nm-idx)<<'\n';
        }else{
            int ind = *lower_bound(a+1,a+k+1,idx);
            cout<<ind-idx<<'\n';
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 