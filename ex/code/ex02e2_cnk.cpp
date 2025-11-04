#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 500;

int a[N+5], qs[N+5], dp[N+5][N+5];
vector<pii> vec;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j==0||i==j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
    cout<<dp[n][k];
}