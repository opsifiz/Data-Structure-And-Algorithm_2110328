#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 20;

bool vis[N+5];
vector<pii> g[N+5];
int mx[N+5];
int k[8];
int target_sum = -1;

map<int,bool> mp;
int st = -1;


int upperbound_sum = 0;

bool dfs(int u, int cursum, int remainUpperbound){
    if(cursum == target_sum) return 1;
    if(cursum > target_sum) return 0;
    if(cursum + remainUpperbound < target_sum) return 0;

    vis[u] = 1;
    for(auto [v, w] : g[u]){
        if(!vis[v]){
            if(dfs(v, cursum+w, remainUpperbound-mx[v])){
                vis[u] = 0;
                return 1;
            }
        }
    }
    vis[u] = 0;
    return 0;
}

void mains(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<8 && cin>>k[i];i++);
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        mx[u] = max(mx[u],w);
        g[v].push_back({u,w});
        mx[v] = max(mx[v],w);
    }
    for(int i=0;i<n;i++) upperbound_sum += mx[i]; //i hate ts
    
    for(int i=0;i<8;i++){
        bool found = 0;
        target_sum = k[i];
        found = 0;
        for(int j=0;j<n;j++){
            found |= dfs(j,0,upperbound_sum-mx[j]);
            if(found) break;
        }
        cout<<(found?"YES\n":"NO\n");
        
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