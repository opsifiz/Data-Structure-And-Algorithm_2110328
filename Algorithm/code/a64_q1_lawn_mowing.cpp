#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 5e5;

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
    int n, q, k;
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qs[i] = qs[i-1]+a[i];
    }
    while(q--){
        int x, y;
        cin>>x>>y;
        x++;
        int l=x, r=n;
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            int cost = qs[mid]-qs[x-1]+(mid-x+1)*k;
            // cout<<x<<' '<<l<<' '<<mid<<' '<<r<<' '<<cost<<'\n';
            if(cost <= y){
                ans = qs[mid]-qs[x-1];
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        cout<<ans<<'\n';
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