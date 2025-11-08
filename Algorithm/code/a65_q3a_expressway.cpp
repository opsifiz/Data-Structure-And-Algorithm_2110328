#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], dis[N+5];
vector<pii> g[N+5];

void mains(){
    priority_queue<pii> pq;
    int n, c;
    cin>>n>>c;
    for(int i=1;i<=n;i++) dis[i] = inf;
    dis[1] = 0;
    dis[2] = c;
    g[1].push_back({2,c});
    g[2].push_back({1,c});
    for(int i=3;i<=n;i++){
        int k; cin>>k;
        while(k--){
            int v, w;
            cin>>v>>w;
            g[i].push_back({v,w});
            g[v].push_back({i,w});
        }
        for(int i=1;i<=n;i++) dis[i] = inf;
        pq.push({dis[1]=0,1});
        while(!pq.empty()){
            int ww = -pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(ww > dis[u]) continue;
            for(auto [v, w]: g[u]){
                if(dis[v] > w+ww){
                    dis[v] = w+ww;
                    pq.push({-dis[v],v});
                }
            }
        }
        cout<<dis[2]<<' ';
        // cout<<'\n';
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