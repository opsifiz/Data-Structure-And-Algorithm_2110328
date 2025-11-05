#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];

void dfs(int u){
    if(vis[u]) return;
    vis[u] = 1;
    for(int v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void mains(){
    set<pii> s;
    int n, m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        int y, m; cin>>y>>m;
        s.insert({y,m});
    }
    while(m--){
        int y, m;
        cin>>y>>m;
        auto x = s.lower_bound({y,m});
        if(x->first == y && x->second == m){
            cout<<"0 0 ";
            continue;
        }
        if(x == s.begin() && ((x->first == y && m < x->second) || (y < x->first))) cout<<"-1 -1 ";
        else{
            x--;
            cout<<(x->first)<<' '<<(x->second)<<' ';
        }
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