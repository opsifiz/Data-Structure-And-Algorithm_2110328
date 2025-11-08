#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 5000;

int board[N+5][N+5];
bool vis[N+5][N+5];
int d[2][4] = {
    {1,0,-1,0},
    {0,1,0,-1}
};

queue<pii> q;

void mains(){
    int cnt = 0;
    int n, m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
            if(board[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int sz = q.size();
        cnt++;
        while(sz--){
            auto [i, j] = q.front(); q.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            if(board[i][j] == 2){
                cout<<cnt;
                return;
            }
            for(int k=0;k<4;k++){
                int ni = i+d[0][k];
                int nj = j+d[1][k];
                if(1<=ni&&ni<=n&&1<=nj&&nj<=m&&!vis[ni][nj]&&board[ni][nj]!=3&&board[ni][nj]!=1){
                    q.push({ni,nj});
                }
            }
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