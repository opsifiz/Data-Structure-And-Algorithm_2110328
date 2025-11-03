#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N = 1000;

int board[N+5][N+5];
bool vis[N+5][N+5];

int d[2][4] = {
    {1,0,-1,0},
    {0,1,0,-1}
};

int main(){
    int n, m, K; cin>>n>>m>>K;
    // K++;
    queue<pii> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
            if(board[i][j]){
                q.push({i,j});
            }
        }
    }

    while(K--){
        // cout<<"------\n";
        int _ = q.size();
        while(_--){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(int k=0;k<4;k++){
                int ni = i+d[0][k];
                int nj = j+d[1][k];
                if(1<=ni&&ni<=n&&1<=nj&&nj<=m&&!vis[ni][nj]&&board[ni][nj]==0){
                    board[ni][nj] = 2;
                    // cout<<"next = "<<ni<<' '<<nj<<'\n';
                    q.push({ni,nj});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
}