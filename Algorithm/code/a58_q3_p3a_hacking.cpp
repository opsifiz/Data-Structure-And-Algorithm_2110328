#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int c[N+5], p[N+5], s[N+5];
int timeTake[N+5];
bool vis[N+5];
vector<int> g[N+5];

void mains(){
    priority_queue<pii> pq;
    int acc = 0;
    int cnt = 0;
    int n, m, k; cin>>n>>m>>k;
    for(int i=0;i<k && cin>>s[i];i++);
    for(int i=0;i<n && cin>>c[i];i++) timeTake[i] = inf;
    for(int i=0;i<k;i++){
        timeTake[s[i]] = c[s[i]];
        pq.push({-timeTake[s[i]],s[i]});
        // cout<<s[i]<<"-th machine take(s) "<<timeTake[s[i]]<<" seconds.\n";
    }
    while(m--){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(!pq.empty()){
        int ww = -pq.top().first;
        int u = pq.top().second; pq.pop();
        // cout<<u<<'\n';
        // if(ww > timeTake[u]) continue;
        if(vis[u]) continue;
        vis[u] = 1;
        // cout<<u<<"-th machine take(s) "<<timeTake[u]<<" seconds.\n";
        acc = max(acc,timeTake[u]);
        // cout<<u<<" "<<acc<<'\n';
        for(int v : g[u]){
            if(!vis[v] && timeTake[v] > timeTake[u]+c[v]){
                timeTake[v] = timeTake[u]+c[v];
                pq.push({-timeTake[v],v});
            }
        }
        
    }
    cout<<acc;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 