#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5], dp[N+5];
vector<pii> vec;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    dp[1] = 1;
    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n];
}