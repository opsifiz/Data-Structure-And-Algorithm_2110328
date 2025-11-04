#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];
bool f;

void dfs(int u, int p){
    if(vis[u]) return;
    vis[u] = 1;
    for(int v : g[u]){
        if(v == p) continue;
        if(vis[v]){
            f = 1;
            return;
        }
        dfs(v,u);
    }
}

void mains(){
    f = 0;
    int n, e;
    cin>>n>>e;
    for(int i=0;i<=n;i++) g[i].clear(), vis[i]=0;
    while(e--){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1);
            if(f){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        mains();
    }
}