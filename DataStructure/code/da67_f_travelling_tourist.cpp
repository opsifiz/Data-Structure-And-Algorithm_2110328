#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 500;

int a[N+5], dp[N+5][N+5];
int s[10];
int dis[1<<20][10];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;

    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<k;j++){
            dis[i][j] = inf;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = inf;
        }
        dp[i][i] = 0;
    }

    for(int i=0;i<k;i++){
        cin>>s[i];
    }
    
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        dp[u][v] = dp[v][u] = w;
    }
    for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = min(dp[i][j],dp[i][x]+dp[x][j]);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    for(int i=0;i<k;i++) dis[1<<i][i] = 0;
    
    for(int state=1;state<(1<<k);state++){
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                dis[state|(1<<i)][i] = min(dis[state|(1<<i)][i],dis[state][j]+dp[s[i]][s[j]]);
                
            }
        }
        // cout<<"state = "<<state<<" : ";
        // for(int i=1;i<(1<<k);i++) cout<<dis[i]<<' '; cout<<'\n';
    }
    int mn = inf;
    for(int i=0;i<k;i++) mn = min(mn,dis[(1<<k)-1][i]);
    // for(int i=0;i<k;i++) cout<<dis[(1<<k)-1][i]<<' '; cout<<'\n';
    cout<<mn<<'\n';
}