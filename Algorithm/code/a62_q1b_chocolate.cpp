#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5, mod = 1000003;

int a[N+5], b[N+5];
int dp[N+5];

void mains(){
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>b[i];
    dp[0] = 1;
    for(int sum=1;sum<=n;sum++){
        for(int i=1;i<=m;i++){
            if(sum >= b[i]){
                dp[sum] += dp[sum-b[i]];
                dp[sum]%=mod;
            }
        }
    }
    cout<<dp[n];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 