#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N = 5000;

string board[N+5];
bool vis[N+5][N+5];

int dir[2][4] = {
    {0,1,0,-1},
    {1,0,-1,0}
};

vector<pii> warp[5+1];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>board[i];
        board[i] = '*'+board[i];
        for(int j=1;j<=m;j++){
            if(isdigit(board[i][j])){
                warp[board[i][j]-'0'].push_back({i,j});
            }
        }
    }
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{1,1}});

    while(!q.empty()){
        auto [dis, ij] = q.front(); q.pop();
        auto [i, j] = ij;

        if(vis[i][j]) continue;
        vis[i][j] = 1;

        if(i == n && j == m){
            cout<<dis<<'\n';
            break;
        }

        if(isdigit(board[i][j])){
            for(auto [ni, nj] : warp[board[i][j]-'0']){
                if(!vis[ni][nj]){
                    q.push({dis,{ni,nj}});
                }
            }
        }

        for(int d=0;d<3;d++){
            int ni = i+dir[0][d], nj = j+dir[1][d];
            if(ni<1||nj<1||ni>n||nj>m) continue;
            if(vis[ni][nj] || board[ni][nj]=='X') continue;
            q.push({dis+1,{ni,nj}});
        }
    }
}