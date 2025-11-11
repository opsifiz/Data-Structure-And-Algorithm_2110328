#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int best = inf;
int n, m;
int c[N+5];

bool vis[N+5];
vector<int> g[N+5];

bool can(int u, int col){
    for(int v : g[u]){
        if(c[v] == col) return 0;
    }
    return 1;
}

void dfs(int i, int mxCol){
    if(i == n){
        best = min(best,mxCol);
        return;
    }
    if(mxCol >= best) return;
    for(int j=1;j<=mxCol+1;j++){
        if(can(i,j)){
            c[i] = j;
            dfs(i+1,max(j,mxCol));
            c[i] = 0;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,0);
    cout<<best;
}