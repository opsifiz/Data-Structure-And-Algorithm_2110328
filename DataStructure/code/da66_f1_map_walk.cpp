#include<bits/stdc++.h>
#define inf 1e18
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 10;

bool vis[N+5][N+5];
bool cant[N+5][N+5];

int n, m;

string cur;
void dfs(int i, int j){
    if(vis[i][j]) return;
    if(cant[i][j]) return;
    if(i<1||i>n||j<1||j>m) return;
    if(i == n && j == m){
        cout<<cur<<'\n';
        return;
    }
    vis[i][j] = 1;
    cur += 'A';
    dfs(i,j+1);
    cur.pop_back();
    cur += 'B';
    dfs(i+1,j);
    cur.pop_back();
    cur += 'C';
    dfs(i-1,j);
    cur.pop_back();
    vis[i][j] = 0;
}

void mains(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>cant[i][j];
        }
    }
    dfs(1,1);
    cout<<"DONE\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    // cin>>tc;
    while(tc--){
        mains();
    }
} 