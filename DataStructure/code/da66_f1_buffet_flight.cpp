#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], b[N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];
int dis[N+5];

void mains(){
    int n, m; cin>>n>>m;
    for(int i=0;i<n;i++) dis[i] = inf;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    while(m--){
        int u, v, w;
        cin>>u>>v;
        g[u].push_back(v);
    }
    priority_queue<pii> pq;
    pq.push({dis[0]=0,0});
    while(!pq.empty()){
        int ww = -pq.top().first;
        int u = pq.top().second; pq.pop();
        if(ww > dis[u]) continue;

        for(int v : g[u]){
            int w = b[u]+a[v];
            if(dis[v] > ww+w){
                dis[v] = ww+w;
                pq.push({-dis[v],v});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<(dis[i]==inf?-1:dis[i])<<' ';
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