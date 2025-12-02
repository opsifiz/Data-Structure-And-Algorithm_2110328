#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 5e5, K = 21;

int dis[2][N+5];
vector<pii> g[2][N+5];
int st[K+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k, src;
    cin>>n>>m>>k>>src;
    for(int i=0;i<=n;i++) dis[0][i] = dis[1][i] = inf;
    while(m--){
        int u, v, w, col;
        cin>>u>>v>>w>>col;
        g[col][v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>st[i];
    }
    
    priority_queue<pii> pq;
    pq.push({dis[0][src]=0,src});
    while(!pq.empty()){
        auto [W, u] = pq.top(); pq.pop();
        W = -W;

        for(auto [v, w] : g[0][u]){
            if(dis[0][v] > dis[0][u]+w){
                dis[0][v] = dis[0][u]+w;
                pq.push({-dis[0][v],v});
            }
        }
    }
    
    pq.push({dis[1][src]=0,src});
    while(!pq.empty()){
        auto [W, u] = pq.top(); pq.pop();
        W = -W;
    
        for(auto [v, w] : g[1][u]){
            if(dis[1][v] > dis[1][u]+w){
                dis[1][v] = dis[1][u]+w;
                pq.push({-dis[1][v],v});
            }
        }
    }

    int sum = 0;
    for(int i=1;i<=k;i++) sum += min(dis[0][st[i]],dis[1][st[i]]);
    cout<<sum<<'\n';

    for(int mask=0;mask<(1<<k);mask++){
        int cur = 0;
        bool can = 1;
        string res;
        for(int i=0;i<k;i++){
            int w = dis[(mask>>i)&1][st[i+1]];
            if(w == inf){
                can = 0;
                break;
            }
            cur += w;
            res += '0'+((mask>>i)&1);
        }
        if(!can) continue;
        if(cur == sum){
            cout<<res<<'\n';
        }
    }
    
}