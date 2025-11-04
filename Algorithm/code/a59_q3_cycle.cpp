#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int deg[N+5];
int a[N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];
int sz = 0;

void dfs(int u){
    if(vis[u]) return;
    vis[u] = 1;
    sz++;
    for(int v : g[u]){
        if(!vis[v] && deg[v]){
            dfs(v);
        }
    }
}

void mains(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(deg[i] == 1){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(deg[u] == 0) continue;
        // cout<<u<<'\n';
        for(int v : g[u]){
            if(deg[v] != 0){
                deg[u]--;
                deg[v]--;
    
                if(deg[v] == 1){
                    q.push(v);
                }
            }
        }
        if(deg[u] != 0){
            cout<<"BAD LOGIC\n";
        }
    }
    for(int i=0;i<n;i++){
        if(deg[i]){
            dfs(i);
            break;
        }
    }
    cout<<sz;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 