#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 1000;

int a[N+5], qs[N+5];
bool vis[N+5][N+5];
vector<int> g[N+5];

void mains(){
    int n, e, k; cin>>n>>e>>k;
    while(e--){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    queue<int> q;
    for(int i=0;i<n;i++){
        while(!q.empty()) q.pop();
        q.push(i);
        int cnt = 0;
        int temp = k+1;
        while(temp--){
            int sz = q.size();
            while(sz--){
                int u = q.front(); q.pop();
                if(vis[i][u]) continue;
                vis[i][u] = 1;
                cnt++;
                for(int v : g[u]){
                    if(!vis[i][v]){
                        q.push(v);
                    }
                }
    
            }
        }
        ans = max(ans,cnt);
    }
    cout<<ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 