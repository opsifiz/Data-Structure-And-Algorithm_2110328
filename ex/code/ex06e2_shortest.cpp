#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 100;

int a[N+5], qs[N+5];
int dis[N+5];
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
    int n, m, s;
    cin>>n>>m>>s;
    for(int i=0;i<=n;i++) dis[i] = inf;
    vector<pair<int,pii>> es;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        es.push_back({u,{v,w}});
    }
    dis[s] = 0;
    bool nig = 0;
    for(int i=0;i<n;i++){
        for(auto e : es){
            int u = e.first;
            int v = e.second.first;
            int w = e.second.second;
            if(dis[u] != inf && dis[v] > dis[u]+w){
                if(i+1 == n){
                    nig = 1;
                    break;
                }else{
                    dis[v] = dis[u]+w;
                }
            }
        }
    }
    if(nig) cout<<"-1\n";
    else for(int i=0;i<n;i++) cout<<dis[i]<<' ';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 