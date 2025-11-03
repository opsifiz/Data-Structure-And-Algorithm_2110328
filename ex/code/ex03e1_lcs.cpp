#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 500;

int dp[N+5][N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin>>s>>t;
    int n = s.size(); s = '*'+s;
    int m = t.size(); t = '*'+t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i] == t[j]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m];
}