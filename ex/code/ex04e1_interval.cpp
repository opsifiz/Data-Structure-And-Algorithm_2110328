#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int dp[N+5];
pii a[N+5];

bool cmp(const pii &l, const pii &r){
    return l.second < r.second;
}

void mains(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first;
    for(int i=1;i<=n;i++) cin>>a[i].second;

    sort(a+1,a+n+1,cmp);
    int prev = 0;
    int cnt = 0;

    for(int i=1;i<=n;i++){
        if(a[i].first >= prev) prev = a[i].second, cnt++;
    }

    cout<<cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 