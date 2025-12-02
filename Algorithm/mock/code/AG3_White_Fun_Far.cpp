#include<bits/stdc++.h>
using namespace std;

const int N = 1e6, mod = 1e8+7;

int dp[N+5][4];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][1]+dp[i-1][3])%mod;
        dp[i][1] = dp[i-1][2];
        dp[i][2] = dp[i-1][0];
        dp[i][3] = (dp[i-1][0]+dp[i-1][1])%mod;
    }
    int ans = (((((dp[n][0]+dp[n][1])%mod)+dp[n][2])%mod)+dp[n][3])%mod;
    cout<<ans;
}