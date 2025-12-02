#include<bits/stdc++.h>
// #define int long long
using namespace std;

const int N = 160;

int qs[N+5][N+5][N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, p; cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=p;k++){
                int temp; cin>>temp;
                qs[i][j][k] = qs[i-1][j][k]+qs[i][j-1][k]+qs[i][j][k-1]-qs[i-1][j-1][k]-qs[i-1][j][k-1]-qs[i][j-1][k-1]+qs[i-1][j-1][k-1]+temp;
            }
        }
    }

    int q; cin>>q;
    while(q--){
        int i, j, k, x, y, z;
        cin>>i>>j>>k>>x>>y>>z;
        int acorn = qs[x][y][z]-qs[i-1][y][z]-qs[x][j-1][z]-qs[x][y][k-1]+qs[i-1][j-1][z]+qs[i-1][y][k-1]+qs[x][j-1][k-1]-qs[i-1][j-1][k-1];
        cout<<acorn<<'\n';
    }
}