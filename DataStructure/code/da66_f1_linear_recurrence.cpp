#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int mod = 32717;

const int N = 1000;

int c[N+5];
int a[N+5];
int dp[N+5];

int32_t main(){
    int n, k;
    cin>>k>>n;
    for(int i=1;i<=k;i++) cin>>c[i];
    for(int i=0;i<k;i++) cin>>a[i];
    for(int i=0;i<k;i++) dp[i] = a[i]%mod;
    for(int i=k;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i] += (c[j]*dp[i-j])%mod;
            dp[i] %= mod;
        }
    }
    cout<<dp[n];
}