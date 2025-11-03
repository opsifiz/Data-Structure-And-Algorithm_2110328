#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int mod = 1e8+7;

const int N = 1e6;

int dp[N+5];

int32_t main(){
    int n; cin>>n;
    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 15;
    for(int i=4;i<=n;i++){
        dp[i] = (((2*dp[i-1])%mod)+(dp[i-3]%mod))%mod;
    }
    cout<<dp[n];
}