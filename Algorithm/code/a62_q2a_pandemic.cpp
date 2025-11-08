#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 500;

int a[N+5], qs[N+5];
bool vis[N+5][N+5];
int board[N+5][N+5];

int d[2][4] = {
    {1,0,-1,0},
    {0,1,0,-1}
};

void mains(){
    queue<pii> q;
    int n, m, t;
    cin>>n>>m>>t;
    t++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
            if(board[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    int cnt = 0;
    while(t--){
        int sz = q.size();
        while(sz--){
            auto [i, j] = q.front(); q.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            cnt++;
            for(int k=0;k<4;k++){
                int ni = i+d[0][k];
                int nj = j+d[1][k];
                if(1<=ni&&ni<=n&&1<=nj&&nj<=m&&!vis[ni][nj] && board[ni][nj] == 0){
                    q.push({ni,nj});
                }
            }
        }
    }
    cout<<cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 