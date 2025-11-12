#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
#define pipii pair<int,pii>
using namespace std;

const int N = 1000;

int a[N+5][N+5];
int vis[N+5][N+5];
int n, m;
int ans = 0;
int mx = 0;

bool cango[7][7][4] = {
    {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
    {{0,0,0,0},{1,0,1,0},{0,0,0,0},{1,0,0,0},{1,0,0,0},{0,0,1,0},{0,0,1,0}},
    {{0,0,0,0},{0,0,0,0},{0,1,0,1},{0,0,0,1},{0,1,0,0},{0,1,0,0},{0,0,0,1}},
    {{0,0,0,0},{0,0,1,0},{0,1,0,0},{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0}},
    {{0,0,0,0},{0,0,1,0},{0,0,0,1},{0,0,0,1},{0,0,0,0},{0,0,1,0},{0,0,1,1}},
    {{0,0,0,0},{1,0,0,0},{0,0,0,1},{1,0,0,1},{1,0,0,0},{0,0,0,0},{0,0,0,1}},
    {{0,0,0,0},{1,0,0,0},{0,1,0,0},{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}}
};

//LURD
int d[2][4] = {
    {0,-1,0,1},
    {-1,0,1,0}
};

void dfs(int i, int j, int pi, int pj, int dis){
    if(++vis[i][j] == 2){
        ans++;
        mx = max(mx,dis);
        return;
    }

    for(int k=0;k<4;k++){
        int ni = i+d[0][k];
        int nj = j+d[1][k];

        if(1<=ni&&ni<=n&&1<=nj&&nj<=m&&cango[a[i][j]][a[ni][nj]][k]&&!(ni==pi&&nj==pj)){
            dfs(ni,nj,i,j,dis+1);
        }
    }
}

void mains(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    queue<pipii> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]){
                // cout<<"DFS : "<<i<<' '<<j<<'\n';
                dfs(i,j,-1,-1,0);
            }
        }
    }
    cout<<ans/2<<' '<<mx;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 