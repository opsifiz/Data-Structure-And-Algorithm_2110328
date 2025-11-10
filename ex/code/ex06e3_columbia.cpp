#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 2e5;

int a[N+5], qs[N+5];
bool vis[N+5];
vector<int> g[N+5];
int board[N+5];
int dis[N+5];

int d[2][4] = {
    {1,0,-1,0},
    {0,1,0,-1}
};

void mains(){
    priority_queue<pair<int,pii>> pq;
    int n, m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int cur = (i-1)*m+j;
            cin>>board[cur];
            dis[cur] = inf;
        }
    }
    pq.push({dis[1]=0,{1,1}});
    while(!pq.empty()){
        int ww = -pq.top().first;
        auto [i, j] = pq.top().second;
        pq.pop();
        int cur = (i-1)*m+j;
        if(ww > dis[cur]) continue;
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(int k=0;k<4;k++){
            int ni = i+d[0][k];
            int nj = j+d[1][k];
            int nx = (ni-1)*m+nj;
            if(ni<1||ni>n||nj<1||nj>m) continue;
            // if(nx == 9){
            //     cout<<cur<<' '<<nx<<' '<<dis[cur]<<' '<<board[nx]<<'\n';
            // }
            if(1<=nx && nx<=n*m && !vis[nx] && dis[nx] > dis[cur]+board[nx]){
                dis[nx] = dis[cur]+board[nx];
                pq.push({-dis[nx],{ni,nj}});
            }
        }
    }
    // cout<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int cur = (i-1)*m+j;
            cout<<dis[cur]<<' ';
        }
        cout<<'\n';
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