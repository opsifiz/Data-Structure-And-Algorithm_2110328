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
    int n; cin>>n;
    int k = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(x){
                g[i].push_back(j);
            }
            k = max(k,(int)g[i].size());
        }
    }
    map<int,int> res;
    for(int i=1;i<=n;i++) res[g[i].size()]++;
    for(int i=0;i<=k;i++){
        cout<<res[i]<<' ';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 