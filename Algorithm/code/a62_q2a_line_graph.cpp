#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];
bool valid = 0;
int sum = -1, ind = -1;

void dfs(int u){
    if(vis[u]) return;
    vis[u] = 1;
    ind++;
    sum += g[u].size();
    if(g[u].size() > 2) valid = 0;
    for(int v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void mains(){
    int cnt = 0;
    int n, e;
    cin>>n>>e;
    while(e--){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            sum = 0;
            ind = 0;
            valid = 1;
            dfs(i);
            if(valid && sum == 2*ind-2){
                cnt++;
            }
        }
    }
    cout<<cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 