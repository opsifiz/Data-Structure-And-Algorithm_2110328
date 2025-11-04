#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 1000;

int a[N+5][N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];
int dp[N+5][N+5];

void mains(){
    int mx = -inf;
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            dp[i][j] = dp[i-1][j-1]+a[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            for(int j=k;j<=n;j++){
                int sum = dp[i][j]-dp[i-k][j-k];
                mx = max(mx,sum);
                // if(sum == 10 || sum == 16){
                //     cout<<i<<' '<<j<<' '<<k<<'\n';
                // }
            }
        }
    }
    cout<<mx;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 