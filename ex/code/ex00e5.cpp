#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

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
    int n, k; cin>>n>>k;
    for(int i=0;i<(1<<n);i++){
        int j=0;
        bool can = 0;
        while(j<n){
            int cnt = 0;
            while(j<n && !((1<<j)&i)) j++;
            while(j<n &&   (1<<j)&i ) cnt++, j++;

            can |= cnt>=k;
        }
        if(can){
            for(int j=n-1;j>=0;j--){
                cout<<((i>>j)&1);
            }
            cout<<'\n';
        }
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