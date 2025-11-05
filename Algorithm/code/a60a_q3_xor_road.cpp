#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5], p[N+5];
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

int fp(int n){
    if(p[n] != n) return p[n] = fp(p[n]);
    return n;
}

void mains(){
    priority_queue<pair<int,pair<int,int>>> pq;
    int n; cin>>n;
    int e = n-1, sum = 0;
    for(int i=1;i<=n;i++){
        p[i] = i;
        cin>>a[i];
        for(int j=1;j<i;j++){
            pq.push({a[i]^a[j],{i,j}});
        }
    }
    while(e && !pq.empty()){
        int val = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        int U = fp(u);
        int V = fp(v);
        if(U != V){
            // cout<<val<<' '<<u<<' '<<v<<'\n';
            p[V] = U;
            sum += val;
            e--;
        }
    }
    cout<<sum;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 