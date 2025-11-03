#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 1000;

int a[N+5][N+5], dp[N+5][N+5];

int32_t main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j] == -1) a[i][j] = inf;
            dp[i][j] = a[i][j];
        }
        dp[i][i] = 0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        mx = max(mx,dp[1][i]);
    }
    cout<<(mx==inf?-1:mx);
}